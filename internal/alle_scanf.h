#ifndef ALLE_SCANF_H_INCLUDED
#define ALLE_SCANF_H_INCLUDED

/*
  Header:
  Name:
  Author: ENYERBER FRANCO
  Date: 00/00/14 00:00
  Description:
*/
#include <allegro.h>
#ifdef __cplusplus
namespace all
{
extern "C" {
#endif // __cplusplus
/**
*  @brief LEER INFORMACION DEL TECLADO
*
**/
void  textscanf(BITMAP *,FONT *,int ,int ,int ,int ,const char *,...);
/**
*  @brief LEER INFORMACION DEL TECLADO
*  @param el ultimo parametro antes del formato es para establecer la longitud
*  en pixeles del texto
**/
void  textscanf_ex(BITMAP *,FONT *,int ,int ,int ,int ,int ,const char *,...);
/**
*  @brief RETORNA LA CADENA LEIDA DESDE EL TECLADO
*
**/
const char *c_line_read_key(BITMAP *,FONT *,int ,int ,int ,int ,int );
/**
*  BUFFER DE TEXTO PARA LAS FUNCIONES DE LECTURA DINAMICA
**/
typedef struct STRING_BUFF
{
    char *str;
    int n;
    int lmt;
}STRING_BUFF;

/**
*  @brief CREA ESPACION EN MEMORIA
*  @param el parametro es el la longitud
*  en pixeles del texto
**/
STRING_BUFF *create_string_buff(int );//crea el espacion en memoria
/**
*  BORRA EL TEXTO QUE CONTENGA EL BUFFER DE TECTO
*  @param BUFFER DE TEXTO
**/
void clear_string_buff(STRING_BUFF *);//linpia el arreglo
/**
*  LIBERA LA MEMORA RESERVADA PARA EL BUFFER DE TEXTO
*  @param BUFFER DE TEXTO
**/
void destroy_string_buff(STRING_BUFF *);//libera memoria
/**
*  LEE DINAMICAMENTE LA INFORMACION PROVENIENTE DEL TECLADO
*  Y LA GUARA EN EL BUFFER DE TEXTO
*  NO PARA EL BUCLE DONDE SE ENCUENTRE
*  @brief LECTURA DINAMICA
*
**/
void all_scan(BITMAP *,FONT *,int ,int ,int ,int ,STRING_BUFF *);//scaneo dinamico
/**
*  @brief EXTRAE IFORMACION DEL BUFFER DE TEXTO
*  @param el parametro puede ser char ,char[] ,char *
*   double , float ,int
**/
void get_scan(STRING_BUFF *,const char *,...);//obtiene la iformacion de string_buff

#ifdef __cplusplus
}
}
#endif // __cplusplus







#endif // ALLE_SCANF_H_INCLUDED
