// *************************************************************************
// 
//  Departamento de Inform�tica de Sistema y Computadores (DISCA)
//  Universidad Politecnica de Valencia.                         
// 
//  Autor: Sergio S�ez (ssaez@disca.upv.es)
// 
//  Fichero: PlanificadorCls.hh
//  
//  Fecha: 
// 
//  Descripci�n: 
// 	 Declaraci�n de la clase 'PlanificadorCls'
// 
// *************************************************************************

#ifndef PlanificadorCls_HH
#define PlanificadorCls_HH

// *** Includes ***********************************************

#include "tipos.h"
#include "ProcesadorCls.hh"

// *** Constantes *********************************************


// *** Clases auxiliares **************************************


// **** CLASE 'PlanificadorCls' ****

class PlanificadorCls
{
public:
  // Inicializa el estado del planificador
  virtual
  int			Inicializa
  (
   void
   )
    { CPU_quantum= MAX_TIEMPO; return OK; };

  // Inicializa el estado del planificador
  virtual
  int			Inicializa
  (
   tiempo_t		quantum
   )
    { CPU_quantum= quantum; return OK; };

  // Informa al planificador de la llegada de una nueva tarea
  virtual 
  int			TareaNueva 
  (
   tarea_activa_t *	tarea
   )=0;

  // Indica cuando se debe realizar la nueva activaci�n
  virtual 
  tiempo_t		SiguienteActivacion 
  (
   const ProcesadorCls& procesador,
   tiempo_t		tiempo_actual
   )=0;

  // Extrae la siguiente tarea a planificar
  virtual 
  tarea_activa_t *	BorraSiguiente 
  (
   void
   )=0;

  // Informa al planificador que la tarea expulsada todavia le queda
  // tiempo de c�mputo
  virtual 
  int			TareaExpulsada 
  (
   tarea_activa_t *	tarea
   )=0;

  // Destructor virtual
  virtual ~PlanificadorCls () {};

protected:
  tiempo_t		CPU_quantum;

};

#endif // *** Include PlanificadorCls.hh
