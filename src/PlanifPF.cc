// *************************************************************************
// 
//  Departamento de Inform�tica de Sistema y Computadores (DISCA)
//  Universidad Politecnica de Valencia.                         
// 
//  Autor: Sergio S�ez (ssaez@disca.upv.es)
// 
//  Fichero: PlanifPF.cc
//  
//  Fecha: 
// 
//  Descripci�n: 
// 	 Implementaci�nde la clase 'PlanifPF'
// 
// *************************************************************************

#define PlanifPF_CC

// *** Includes ***********************************************

#include "PlanifPF.hh"

// *** Definiciones Externas **********************************

// *** M�todos P�blicos ***************************************

// *** PlanifPF::TareaNueva
// Informa al planificador de la llegada de una nueva tarea

int PlanifPF::TareaNueva 
( 
 tarea_activa_t * tarea
 )
{
  // *** Cuerpo principal del m�todo

  cl_preparadas.push(tarea);

  return OK;

} // end PlanifPF::TareaNueva


// *** PlanifPF::SiguienteActivacion
// Indica cuando se debe realizar la nueva activaci�n

tiempo_t PlanifPF::SiguienteActivacion 
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
      if (procesador.PrioridadTarea(tiempo_actual) <= 
	  cl_preparadas.top()->prioridad)
	return procesador.SiguienteLibre(tiempo_actual);
      else
	return tiempo_actual;	// Expulsi�n
  else
    return MAX_TIEMPO;

} // end PlanifPF::SiguienteActivacion


// *** PlanifPF::BorraSiguiente
// Extrae la siguinte tarea a planificar

tarea_activa_t * PlanifPF::BorraSiguiente ( )
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

} // end PlanifPF::BorraSiguiente


// *** PlanifPF::TareaExpulsada
// Informa al planificador que la tarea expulsada todavia le queda
// tiempo de c�mputo

int PlanifPF::TareaExpulsada 
( 
 tarea_activa_t *	tarea
 )
{
  // *** Cuerpo principal del m�todo

  cl_preparadas.push(tarea);

  return OK;

} // end PlanifPF::TareaExpulsada


// *** PlanifPF::~PlanifPF

PlanifPF::~PlanifPF ()
{

} // end PlanifPF::~PlanifPF

// *** M�todos Privados ***************************************

