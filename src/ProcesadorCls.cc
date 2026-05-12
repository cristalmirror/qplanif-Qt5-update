// *************************************************************************
// 
//  Departamento de Inform�tica de Sistema y Computadores (DISCA)
//  Universidad Politecnica de Valencia.                         
// 
//  Autor: Sergio S�ez (ssaez@disca.upv.es)
// 
//  Fichero: ProcesadorCls.cc
//  
//  Fecha: 
// 
//  Descripci�n: 
// 	 Implementaci�nde la clase 'ProcesadorCls'
// 
// *************************************************************************

#define ProcesadorCls_CC

// *** Includes ***********************************************

#include <stddef.h>
#include "ProcesadorCls.hh"

// *** Definiciones Externas **********************************

// *** M�todos P�blicos ***************************************

// *** ProcesadorCls::ProcesadorCls

ProcesadorCls::ProcesadorCls ( )
{
  // *** Cuerpo principal del m�todo

  tarea_ejecucion= NULL;
  instante_activacion= 0;

} // end ProcesadorCls::ProcesadorCls

// *** M�todos Privados ***************************************


// *** ProcesadorCls::SiguienteLibre

tiempo_t ProcesadorCls::SiguienteLibre 
( 
 tiempo_t		tiempo_actual
 ) const
{
  // *** Cuerpo principal del m�todo
  
  if (tarea_ejecucion == NULL)
    return (MAX_TIEMPO);
  else
    return (instante_activacion + tarea_ejecucion->computo);

} // end ProcesadorCls::SiguienteLibre


// *** ProcesadorCls::TareaNueva

tarea_activa_t * ProcesadorCls::TareaNueva 
( 
 tiempo_t		tiempo_actual,
 tarea_activa_t *	tarea
 )
{
  // *** Objetos Locales. Inicializaci�n

  tarea_activa_t *	tarea_expulsada= tarea_ejecucion;

  // *** Cuerpo principal del m�todo

  if (tarea_expulsada != NULL)
    {
      tarea_expulsada->computo -= (tiempo_actual - instante_activacion); 
      tarea_expulsada->llegada= tiempo_actual;
    } // endif

  tarea_ejecucion= tarea;
  instante_activacion= tiempo_actual;

  return (tarea_expulsada);

} // end ProcesadorCls::TareaNueva


// *** ProcesadorCls::BorraSiguiente

tarea_activa_t * ProcesadorCls::BorraSiguiente 
( 
 tiempo_t		tiempo_actual
 )
{
  // *** Objetos Locales. Inicializaci�n
  
  tarea_activa_t *	tarea_expulsada= tarea_ejecucion;
  
  // *** Cuerpo principal del m�todo

  if (tarea_expulsada != NULL)
    {
      tarea_expulsada->computo -= (tiempo_actual - instante_activacion);
      tarea_expulsada->llegada= tiempo_actual;
    } // endif

  tarea_ejecucion= NULL;
  instante_activacion= tiempo_actual;

  return (tarea_expulsada);

} // end ProcesadorCls::BorraSiguiente


