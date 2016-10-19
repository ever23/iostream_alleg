/**
 * Name: iostream_alleg.h
 * Author: ENYERBER FRANCO
 * email: enyerverfranco@outlook.com
 * Date: 3/01/15 07:34
 * Description: funciones para simplifica la entrada y salida de texto en allegro
 * al estilo iostream
**/
#ifndef IOSTREAM_ALLEG_H_INCLUDED
#define IOSTREAM_ALLEG_H_INCLUDED
#ifdef __al_included_allegro5_allegro_h
#error no compatible con allegro5
#endif // __al_included_allegro5_allegro_h

#include "internal/alle_scanf.h"
#ifdef __cplusplus

#include "internal/alle_stream.hpp"
#include "internal/cadena.hpp"

namespace all
{
/**
*  @brief SALTA UNA LINEA
**/
#define ENDL          _endl     //1 salto de linea
/**
*  @brief SALTA DOS LINEA
**/
#define ENDL2         _endl2    //doble salto
/**
*  LEE DINAMICAMENTE LA INFORMACION PROVENIENTE DEL TECLADO
*  Y LA GUARDA EN EL BUFFER DE TEXTO
*  NO PARA EL BUCLE DONDE SE ENCUENTRE
*  @brief LECTURA DINAMICA
*
**/
#define GETKEY        _getkey   //1 lectura dinamica
/**
*  @brief BORRA EL BUFFER DE TEXTO
**/
#define CLEARBUF      _clearbuf //limpia buffer de la clase
/**
*  COORDENADAS DONDE SE IMPRIMIRA EL TEXTO SIGUIENTE
*  SE PASAN LOS PARAMETROS X Y
*  @brief XY(int x,int y);  CAMBIAR LAS COORDENADAS DEL TEXTO
*  @param int X, int Y
**/
#define XY(int_x,int_y) _xy(int_x,int_y)      //SALTA AL LA POCICION X,Y
/**
*  @brief BMP(BITMAP *buffer,int color); CAMBIA EL BITMAP DE IMPRECION
*  @param EL SEGUNDO PARAMETRO ES OPCIONAL
**/
#define BMP           _bmp      //carga un BITMAP
/**
*  longitud en pixeles maxima del texto  para las
*  funciones de entrada
*  @brief LMT(int longitud); ESTABLECE LA LONGITUD EN PIXELES DEL TEXTO
**/
#define LMT(int_lmt)           _lmt(int_lmt)       //establece el limite de texto
}

#endif // __cplusplus

#endif // IOSTREAM_ALLEG_H_INCLUDED
