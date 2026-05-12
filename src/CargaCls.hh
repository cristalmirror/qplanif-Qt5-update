// *************************************************************************
// 
//  Departamento de Inform�tica de Sistema y Computadores (DISCA)
//  Universidad Politecnica de Valencia.                         
// 
//  Autor: Sergio S�ez (ssaez@disca.upv.es)
// 
//  Fichero: CargaCls.hh
//  
//  Fecha: 
// 
//  Descripci�n: 
// 	 Declaraci�n de la clase 'CargaCls'
// 
// *************************************************************************

#ifndef CargaCls_HH
#define CargaCls_HH

// *** Includes ***********************************************

#include "tipos.h"
#include "ColasCls.hh"

// *** Constantes *********************************************


// *** Clases auxiliares **************************************


// **** CLASE 'CargaCls' ****

class CargaCls
{
public:
  CargaCls 
  (
   void
   );
  // Inicializa el manejador de la carga
  int			Inicializa 
  (
   tarea_c *		TablaTareas,
   int			NumeroTareas
   );
  // Informa de la siguiente activaci�n
  tiempo_t		SiguienteLlegada 
  (
   void
   );
  // Saca de la lista la siguiente activaci�n
  tarea_activa_t *	BorraSiguiente 
  (
   void
   );
  // Termina una subtarea. Devuelve true si era la �ltima subtarea
  bool			TareaTerminada 
  (
   tarea_activa_t *	tarea,
   tiempo_t		tiempo_actual
   );
  // Termina la simulaci�n de la carga
  void			Termina
  (
   void
   );

private:
  cola_llegada_c	cl_llegadas;
  cola_fifo_c		cl_subtareas;

  tarea_c *		tbl_tareas;
  int			n_tareas;

};

#endif // *** Include CargaCls.h

