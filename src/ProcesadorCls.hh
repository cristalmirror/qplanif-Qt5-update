// *************************************************************************
// 
//  Departamento de Inform�tica de Sistema y Computadores (DISCA)
//  Universidad Politecnica de Valencia.                         
// 
//  Autor: Sergio S�ez (ssaez@disca.upv.es)
// 
//  Fichero: ProcesadorCls.hh
//  
//  Fecha: 
// 
//  Descripci�n: 
// 	 Declaraci�n de la clase 'ProcesadorCls'
// 
// *************************************************************************

#ifndef ProcesadorCls_HH
#define ProcesadorCls_HH

// *** Includes ***********************************************

#include "tipos.h"
#include <cstddef>

// *** Constantes *********************************************


// *** Clases auxiliares **************************************


// **** CLASE 'ProcesadorCls' ****

class ProcesadorCls
{
public:
  ProcesadorCls 
  (
   void
   );

  // Inicializaci�n

  void			Inicializa 
  (
   void 
   )
    {
      tarea_ejecucion= NULL;
      instante_activacion= 0;
    }; 

  // Coloca en ejecuci�n la 'Tarea' y devuelve la tarea que estaba en
  // Ejecuci�n, NULL si estaba vacio.
  tarea_activa_t *	TareaNueva 
  (
   tiempo_t		tiempo_actual,
   tarea_activa_t *	tarea
   );

  // Saca de ejecuci�n la tarea. Se debe utilizar s�lo cuando la tarea
  // en ejecuci�n ha terminado
  tarea_activa_t *	BorraSiguiente 
  (
   tiempo_t		tiempo_actual
   );

  // *** Informaci�n ************************************************

  // Informa si el procesador est� libre
  bool			EstaLibre
  (
   ) const
    {
      return (tarea_ejecucion == NULL);
    };

  // Informa del siguiente instante en que estar� el procesador libre 
  tiempo_t		SiguienteLibre 
  (
   tiempo_t		tiempo_actual
   ) const;

  // Devuelve el tiempo que le queda a la tarea en ejecuci�n por
  // ejecutarse
  // PRE: !(EstaLibre())
  tiempo_t		ComputoTarea
  (
   tiempo_t		tiempo_actual
   ) const 
    {
      return tarea_ejecucion->computo - (tiempo_actual - instante_activacion);
    };

  // Devuelve el tiempo que lleva la tarea en ejecuci�n
  // PRE: !(EstaLibre())
  tiempo_t		EjecutandoseTarea
  (
   tiempo_t		tiempo_actual
   ) const 
    {
      return tiempo_actual - instante_activacion;
    };

  // Devuelve la prioridad de la tarea en ejecuci�n
  // PRE: !(EstaLibre())
  int			PrioridadTarea
  (
   tiempo_t		tiempo_actual
   ) const 
    {
      return tarea_ejecucion->prioridad;
    };

private:
  tarea_activa_t *	tarea_ejecucion;
				// Tarea en ejecuci�n
  tiempo_t		instante_activacion;
				// Instante en el que entro la tarea
				// que est� en ejecuci�n
};

#endif // *** Include ProcesadorCls.hh

