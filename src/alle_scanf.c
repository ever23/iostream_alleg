/*
  Source:
  Name:
  Author: ENYERBER FRANCO
  Date: 00/00/14 00:00
  Description:
*/
#include "../internal/alle_scanf.h"
#include <stdarg.h>
#include <string.h>


STRING_BUFF *create_string_buff(int TAMANO)
{
    STRING_BUFF *create=malloc(1);
    create->str=malloc(1);
    strcpy(create->str,"");
    create->n=0;
    create->lmt=TAMANO;
    return create;
}
void push_char(STRING_BUFF *cad,char car)
{
    char au[cad->n];
    char a[2];
    strcpy(au,cad->str);
    free(cad->str);
    cad->str=malloc(cad->n+2);
    strcpy(cad->str, au);
    a[0]=car;
    a[1]='\0';
    strcat(cad->str,a);
    cad->n++;
}
void pop_char(STRING_BUFF *cad)
{
    char au[cad->n+1];
    if(cad->n>0)
    {
        strcpy(au,cad->str);
        cad->n--;
        au[cad->n]='\0';
        free(cad->str);
        cad->str=malloc(cad->n+1);
        strcpy(cad->str,au);
    }
}

void clear_string_buff(STRING_BUFF *string_buff)
{
    free(string_buff->str);
    string_buff->str=malloc(1);
    strcpy(string_buff->str,"");
    string_buff->n=0;
}

void destroy_string_buff(STRING_BUFF *string_buff)
{
    free(string_buff->str);
}



void all_scan(BITMAP *buffer,FONT *fuente,int x,int y,int color,int modo,STRING_BUFF *string_buff)
{
    if(keypressed())
    {
        char lt=readkey();
        if(lt>=32 && lt<=174 &&(text_length(fuente, string_buff->str) < string_buff->lmt ))
        {
            push_char(string_buff,lt);
        }
        if(lt==8 && string_buff->n>0)
        {
            pop_char(string_buff);
        }
    }
    textout_ex(buffer,fuente, string_buff->str, x, y, color, modo);
}

const char *c_line_read_key(BITMAP *buffer,FONT *fuente,int X,int Y,int color,int modo,int lmt)
{
    int prin_mouse=0;
    if(install_mouse())
    {
        remove_mouse();
        prin_mouse=0;
    }
    else
    {
        prin_mouse=1;
    }
    clear_keybuf();
    BITMAP *SUBSCREN = create_bitmap(screen->w,  screen->h);
    STRING_BUFF *string_buff=create_string_buff(lmt);
    rest(5);
    do
    {
        blit(buffer,SUBSCREN, 0, 0, 0, 0, screen->w, screen->h);

        if(prin_mouse==1)
            draw_sprite(SUBSCREN,mouse_sprite,mouse_x,mouse_y);

       all_scan(SUBSCREN,fuente, X, Y, color, modo, string_buff);

        blit(SUBSCREN,screen, 0, 0,0 ,0 , screen->w, screen->h);
         rest(1);
    }
    while(!key[KEY_ENTER]);
    clear_to_color(SUBSCREN,1);
    destroy_bitmap(SUBSCREN);
    char *ret=malloc(string_buff->n+1);
    strcpy(ret,string_buff->str);
    destroy_string_buff(string_buff);
    return ret;

}




void get_scan(STRING_BUFF *string_buff,const char *fmt,...)
{
    char *szarg;
    int *iarg;
    float *farg;
    long *larg;
    va_list fmts_;
    va_start(fmts_, fmt);
    int i=0;
    for( i = 0; i < strlen(fmt); i++)
    {
        if(fmt[i]=='%')
        {
            switch(fmt[i+1])
            {

            case 's': /* Cadena de caracteres */
            {
                szarg = va_arg(fmts_, char*);
                strcpy(szarg,string_buff->str );
            }
            break;
            case 'i': /* Entero */
            {
                iarg = va_arg(fmts_, int*);
                *iarg = atoi(string_buff->str);
            }
            break;
            case 'f':/*flotante */
            {
                farg = va_arg(fmts_, float*);
                *farg = atof(string_buff->str);
            }
            break;
            case 'l':/*long*/
            {
                larg = va_arg(fmts_, long*);
                *larg = atol(string_buff->str);
            }
            break;
            }
        }
    }
    va_end(fmts_);
}


void textscanf_ex(BITMAP *buffer,FONT *fuente,int X,int Y,int color,int modo,int lmt,const char *fmt,...)
{
    char *szarg;
    int *iarg;
    float *farg;
    long *larg;
    va_list fmts_;
    va_start(fmts_, fmt);
    int i=0;
    for( i = 0; i < strlen(fmt); i++)
    {
        if(fmt[i]=='%')
        {
            switch(fmt[i+1])
            {
            case 's': /* Cadena de caracteres */
            {
                szarg = va_arg(fmts_, char*);
                strcpy(szarg,c_line_read_key(buffer, fuente, X, Y, color,modo,lmt));
            }
            break;
            case 'i': /* Entero */
            {
                iarg = va_arg(fmts_, int*);
                *iarg = atoi(c_line_read_key(buffer, fuente, X, Y, color,modo,lmt));
            }
            break;
            case 'f':/*flotante */
            {
                farg = va_arg(fmts_, float*);
                *farg = atof(c_line_read_key(buffer, fuente, X, Y, color,modo,lmt));
            }
            break;
            case 'l':/*long*/
            {
                larg = va_arg(fmts_, long*);
                *larg = atol(c_line_read_key(buffer, fuente, X, Y, color,modo,lmt));
            }
            break;
            }
        }
    }
    va_end(fmts_);
}
void textscanf(BITMAP *buffer,FONT *fuente,int X,int Y,int color,int modo,const char *fmt,...)
{
    char *szarg;
    int *iarg;
    float *farg;
    long *larg;
    int lmt=1360;
    va_list fmts_;
    va_start(fmts_, fmt);
    int i=0;
    for( i = 0; i < strlen(fmt); i++)
    {
        if(fmt[i]=='%')
        {
            switch(fmt[i+1])
            {

            case 's': /* Cadena de caracteres */
            {
                szarg = va_arg(fmts_, char*);
                strcpy(szarg,c_line_read_key(buffer, fuente, X, Y, color,modo,lmt));
            }
            break;
            case 'i': /* Entero */
            {
                iarg = va_arg(fmts_, int*);
                *iarg = atoi(c_line_read_key(buffer, fuente, X, Y, color,modo,lmt));
            }
            break;
            case 'f':/*flotante */
            {
                farg = va_arg(fmts_, float*);
                *farg = atof(c_line_read_key(buffer, fuente, X, Y, color,modo,lmt));
            }
            break;
            case 'l':/*long*/
            {
                larg = va_arg(fmts_, long*);
                *larg = atol(c_line_read_key(buffer, fuente, X, Y, color,modo,lmt));
            }
            break;
            }
        }
    }
    va_end(fmts_);
}
