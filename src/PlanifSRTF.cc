// *************************************************************************
// 
//  Departamento de Inform�tica de Sistema y Computadores (DISCA)
//  Universidad Politecnica de Valencia.                         
// 
//  Autor: Sergio S�ez (ssaez@disca.upv.es)
// 
//  Fichero: PlanifSRTF.cc
//  
//  Fecha: 
// 
//  Descripci�n: 
// 	 Implementaci�nde la clase 'PlanifSRTF'
// 
// *************************************************************************

#define PlanifSRTF_CC

// *** Includes ***********************************************

#include "PlanifSRTF.hh"

// *** Definiciones Externas **********************************

// *** M�todos P�blicos ***************************************

// *** PlanifSRTF::TareaNueva
// Informa al planificador de la llegada de una nueva tarea

int PlanifSRTF::TareaNueva 
( 
 tarea_activa_t *	tarea
 )
{
  // *** Cuerpo principal del m�todo

  cl_preparadas.push(tarea);

  return OK;

} // end PlanifSRTF::TareaNueva


// *** PlanifSRTF::SiguienteActivacion
// Indica cuando se debe realizar la nueva activaci�n

tiempo_t PlanifSRTF::SiguienteActivacion 
( 
 const ProcesadorCls&	procesador,
 tiempo_t		tiempo_actual
 )
{
  // *** Cuerpo principal del m�todo

  if (!cl_preparadas.empty())
    if (procesador.EstaLibre())
      return tiempo_actual;
    else
      if (procesador.ComputoTarea(tiempo_actual) <= 
	  cl_preparadas.top()->computo)
	return procesador.SiguienteLibre(tiempo_actual);
      else
	return tiempo_actual;	// Expulsi�n
  else
    return MAX_TIEMPO;

} // end PlanifSRTF::SiguienteActivacion


// *** PlanifSRTF::BorraSiguiente
// Extrae la siguinte tarea a planificar

tarea_activa_t * PlanifSRTF::BorraSiguiente ( )
{
  // *** Objetos Locales. Inicializaci�n

  tarea_activa_t *	sig_tarea;

  // *** Cuerpo principal del m�todo

  if (!cl_preparadas.empty())
    {
      sig_tarea= cl_preparadas.top();
      cl_preparadas.pop();
    }
  else
    sig_tarea= NULL;

  return sig_tarea;

} // end PlanifSRTF::BorraSiguiente


// *** PlanifSRTF::TareaExpulsada
// Informa al planificador que la tarea expulsada todavia le queda
// tiempo de c�mputo

int PlanifSRTF::TareaExpulsada 
( 
 tarea_activa_t *	tarea
 )
{
  // *** Cuerpo principal del m�todo

  cl_preparadas.push(tarea);

  return OK;

} // end PlanifSRTF::TareaExpulsada


// *** PlanifSRTF::~PlanifSRTF

PlanifSRTF::~PlanifSRTF ()
{

} // end PlanifSRTF::~PlanifSRTF

// *** M�todos Privados ***************************************

