// *************************************************************************
// 
//  Departamento de Inform�tica de Sistema y Computadores (DISCA)
//  Universidad Politecnica de Valencia.                         
// 
//  Autor: Sergio S�ez (ssaez@disca.upv.es)
// 
//  Fichero: CargaCls.cc
//  
//  Fecha: 
// 
//  Descripci�n: 
// 	 Implementaci�nde la clase 'CargaCls'
// 
// *************************************************************************

#define CargaCls_CC

// *** Includes ***********************************************

#include <stdio.h>
#include "CargaCls.hh"

// *** Definiciones Externas **********************************

// *** M�todos P�blicos ***************************************

// *** CargaCls::CargaCls

CargaCls::CargaCls ( )
{
  // *** Objetos Locales. Inicializaci�n
  
  
  // *** Cuerpo principal del m�todo
  
  
} // end CargaCls::CargaCls


// *** CargaCls::Inicializa
// Inicializa el manejador de la carga

int CargaCls::Inicializa 
( 
 tarea_c *		TablaTareas,
 int			NumeroTareas
 )
{
  // *** Objetos Locales. Inicializaci�n

  tarea_activa_t *	tarea;

  // *** Cuerpo principal del m�todo

  tbl_tareas= TablaTareas;
  n_tareas= NumeroTareas;

  for (int i= 0; i<n_tareas; i++)
    {
      // --- Crea la primera subtarea de cada tarea del conjunto 
      tarea= new tarea_activa_t;
      tarea->ident= i;
      tarea->subident= 0;
      tarea->llegada= tbl_tareas[i].llegada;
      tarea->computo= tbl_tareas[i].subtarea[0].tiempo;
      tarea->recurso= tbl_tareas[i].subtarea[0].recurso;
      tarea->prioridad= tbl_tareas[i].prioridad;

      // --- Inserta la tarea
      cl_llegadas.push(tarea);

#ifdef DEBUG
      fprintf(stdout, "LD>> t: Inicio Tk: %d-%d "
	      "(O: %ld, C: %ld, R: %d, Pr: %d)\n",
	      tarea->ident, tarea->subident,
	      tarea->llegada, tarea->computo, 
	      tarea->recurso, tarea->prioridad  
	      );
#endif
    } // endfor
  
  return OK;

} // end CargaCls::Inicializa


// *** CargaCls::SiguienteLlegada
// Informa de la siguiente activaci�n

tiempo_t CargaCls::SiguienteLlegada ( )
{
  // *** Cuerpo principal del m�todo

  if (!cl_subtareas.empty())
    return (cl_subtareas.front()->llegada);
  else if (!cl_llegadas.empty())
    return (cl_llegadas.top()->llegada);
  else
    return (MAX_TIEMPO);

} // end CargaCls::SiguienteLlegada


// *** CargaCls::BorraSiguiente
// Saca de la lista la siguiente activaci�n

tarea_activa_t * CargaCls::BorraSiguiente ( )
{
  // *** Objetos Locales. Inicializaci�n

  tarea_activa_t *	tarea;
  tarea_activa_t *	sig_tarea;

  // *** Cuerpo principal del m�todo

  if (!cl_subtareas.empty())
    {
      sig_tarea= cl_subtareas.front();
      cl_subtareas.pop();
    } 
  else if (!cl_llegadas.empty())
    {
      sig_tarea= cl_llegadas.top();
      cl_llegadas.pop();
				// Tarea peri�dica
      if (tbl_tareas[sig_tarea->ident].periodo > 0)
	{
	  int i= sig_tarea->ident;

	  // --- Genera la siguiente ocurrencia
	  tarea= new tarea_activa_t;
	  tarea->ident= i;
	  tarea->subident= 0;
	  tarea->llegada= sig_tarea->llegada + tbl_tareas[i].periodo;
	  tarea->computo= tbl_tareas[i].subtarea[0].tiempo;
	  tarea->recurso= tbl_tareas[i].subtarea[0].recurso;
	  tarea->prioridad= tbl_tareas[i].prioridad;

	  // --- Inserta la tarea
	  cl_llegadas.push(tarea);

	} // endif
    }
  else
    sig_tarea= NULL;

#ifdef DEBUG
  if (sig_tarea != NULL)
    {
      fprintf(stdout, "LD>> Tk: %d-%d "
	      "(O: %ld, C: %ld, R: %d, Pr: %d)\n", 
	      sig_tarea->ident, sig_tarea->subident,
	      sig_tarea->llegada, sig_tarea->computo, 
	      sig_tarea->recurso, sig_tarea->prioridad  
	      );
    } // endif
#endif

  return (sig_tarea);

} // end CargaCls::BorraSiguiente


// *** CargaCls::TareaTerminada
// Termina una subtarea

bool CargaCls::TareaTerminada
(
 tarea_activa_t *	tarea,
 tiempo_t		tiempo_actual
 )
{
  // *** Objetos Locales. Inicializaci�n

  int			i= tarea->ident;
  int			sig_subtarea= tarea->subident+1;

  // *** Cuerpo principal del m�todo

  if (tbl_tareas[i].Nsubtareas > sig_subtarea)
    {
      // --- Genera la siguiente subtarea
      tarea->subident= sig_subtarea;
      tarea->llegada= tiempo_actual;
      tarea->computo= tbl_tareas[i].subtarea[sig_subtarea].tiempo;
      tarea->recurso= tbl_tareas[i].subtarea[sig_subtarea].recurso;
      tarea->prioridad= tbl_tareas[i].prioridad;
      
      // --- Inserta la tarea
      cl_subtareas.push(tarea);
      return false;
    }
  else
    {
      delete tarea;
      return true;
    } // endif

} // end CargaCls::TareaTerminada


// *** CargaCls::Termina
// Termina la simulaci�n de la carga

void CargaCls::Termina ( )
{
  // *** Cuerpo principal del m�todo

  while (!cl_subtareas.empty())
    {
      delete (cl_subtareas.front());
      cl_subtareas.pop();
    } // endwhile

  while (!cl_llegadas.empty())
    {
      delete (cl_llegadas.top());
      cl_llegadas.pop();
    } // endwhile

} // end CargaCls::Termina

// *** M�todos Privados ***************************************

