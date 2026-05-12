// *************************************************************************
// 
//  Departamento de Inform�tica de Sistema y Computadores (DISCA)
//  Universidad Politecnica de Valencia.                         
// 
//  Autor: Sergio S�ez (ssaez@disca.upv.es)
// 
//  Fichero: DescripcionCls.hh
//  
//  Fecha: 
// 
//  Descripci�n: 
// 	 Declaraci�n de la clase 'DescripcionCls'
// 
// *************************************************************************

#ifndef DescripcionCls_HH
#define DescripcionCls_HH

// *** Includes ***********************************************

#include <stdio.h>
#include "tipos.h"
#include "EventosCls.hh"

// *** Constantes *********************************************

//  #define DEBUG

// **** CLASE 'DescripcionCls' ****


class DescripcionCls
{
public:
  // Genera una lista de eventos con la descripci�n de cada tarea
  void			Descripcion 
  (
   tarea_c *		tbl_tareas,
   int			num_tareas,
   int			num_recursos,
   EventosCls&		lst_eventos
   );
};
 
#endif // *** Include DescripcionCls.hh
