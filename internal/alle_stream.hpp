//- alle_stream.h -------------------------------------------------------------

/**
 * Name: CLASE ALLE_STREAM
 * Author: ENYERBER FRANCO
 * email: enyerverfranco@outlook.com
 * Date: 3/01/15 07:34
 * Description: DECLARACION DE LA CLASE PARA FLUJOS DE ENTRADA Y DE SALIDA DE TEXTO EN TECLADO Y PANTALLA
 * PARA ALLEGRO
**/


#ifndef ALLE_STREAM_H
#define ALLE_STREAM_H


#include "cadena.hpp"
#include <allegro.h>
namespace all
{


#define _ALLE_ENDL_          0x1
#define _ALLE_ENDL2_         0x2
#define _ALLE_GETKEY_        0x3
#define _ALLE_CLEARBUF_      0x4
#define _ALLE_XY_            0x5
#define _ALLE_BMP_           0x6
#define _ALLE_LMT_           0x7
#define colordft             0xffffff
/**
*  CONTROLA LA ENTRADA Y SALIDA DE TEXTO PARA ALLEGRO
*  @brief CLASE ALLE_STREAM
**/
class ALLE_STREAM
{
public:
    /**
    * CONSTRUCTOR POR DEFECTO
    **/
    ALLE_STREAM();
    /**
    * CONSTRUCTOR COPIA
    **/
    ALLE_STREAM(const ALLE_STREAM&);//ctor copy
    /**
    * CONSTRUCTOR INICIADOR
    **/
    ALLE_STREAM(int,int,int,int);
    /**
    * CONSTRUCTOR INICIA Y CARGA BITMAP DE IMPRECION
    **/
    ALLE_STREAM(BITMAP *,int,int,int,int);
    /**
    * DESTRUCTOR
    **/
    ~ALLE_STREAM();
    //sub_constructores
    /**
    *  @brief INICIALISA EL OBJETO ALLE_STREAM
    **/
    void iostream_alleg_init(int,int,int,int);
    /**
    *  @brief INICIALISA EL OBJETO ALLE_STREAM
    *  @param el primer parametro es el bitmap donde se imprimira el texto
    **/
    void iostream_alleg_init(BITMAP *,int,int,int,int);

    /**
    *  para los iteradores como ENDL XY O BMP
    *  @brief CLASE ITERADOR
    **/
    class iterador
    {
    public:
        iterador(int n):INTER(n)
        {
            bitmap_i=NULL;
        }
        ~iterador();
        iterador operator ()(int,int);
        iterador operator ()(BITMAP *,int COLOR=-5);
        iterador operator ()(int );
    private:
        void delete_();
        const int INTER;
        int x_i,y_i;
        int lmt;
        int color_i;
        BITMAP *bitmap_i;
        friend class ALLE_STREAM;
    };//
    //llamadas
    /**
    *  OPERADOR DE LLAMADA SOBRECARGADO PASANDO COMO PARAMETRO X  Y
    *  DONDE SE INPRIMIRA EL TEXTO LEIDO
    *  @brief LEE IFORMACION PROVENIETE DEL TECLADO
    **/
    void operator ()(int ,int ,char &);
    void operator ()(int ,int ,char *&);
    void operator ()(int ,int ,char []);
    void operator ()(int ,int ,alle_string &);
    void operator ()(int ,int ,std::string &);
    void operator ()(int ,int ,double &);
    void operator ()(int ,int ,float &);
    void operator ()(int ,int ,int &);
    void operator ()(int ,int ,const iterador &);


    //flujos de entrada
    /**
    *  OPERADOR >> SOBRECARGADO
    *  @brief LEE IFORMACION PROVENIETE DEL TECLADO
    **/
    ALLE_STREAM &operator >>(char &);
    ALLE_STREAM &operator >>(char *&);
    ALLE_STREAM &operator >>(char []);
    ALLE_STREAM &operator >>(alle_string &);
    ALLE_STREAM &operator >>(std::string &);
    ALLE_STREAM &operator >>(double &);
    ALLE_STREAM &operator >>(float &);
    ALLE_STREAM &operator >>(int &);
    //flujos de salida
    /**
    *  @brief IMPRIME TEXTO EN EL BITMAP Y POCICION  ANTES CARGADO
    *
    **/
    ALLE_STREAM &operator <<(alle_string);
    ALLE_STREAM &operator <<(const char *);
    ALLE_STREAM &operator <<(char);
    ALLE_STREAM &operator <<(std::string );
    ALLE_STREAM &operator <<(float);
    ALLE_STREAM &operator <<(int);
    ALLE_STREAM &operator <<(double);
    ALLE_STREAM &operator <<(const iterador&);
    /**
    operadores que podrian sobrecargarse
    ALLE_STREAM operator >>(long &);
    ALLE_STREAM operator <<(long);
    **/
//get
    /**
    *  @brief INSERTA UN CADENA EN EL BUFFER DE TEXTO
    *  @param cadena de texto
    *
    **/
    void set_stringbuff(const char *);
    /**
    *  @brief ESTRAE IFORMACION DEL BUFFER DE TEXTO
    *  @param char
    **/
    void get_var(char &);
    /**
    *  @brief ESTRAE IFORMACION DEL BUFFER DE TEXTO
    *  @param char[]
    **/
    void get_var(char []);
    /**
    *  @brief ESTRAE IFORMACION DEL BUFFER DE TEXTO
    *  @param char *
    **/
    void get_var(char *&);
     /**
    *  @brief ESTRAE IFORMACION DEL BUFFER DE TEXTO
    *  @param all::alle_string
    **/
    void get_var(alle_string &);
    /**
    *  @brief ESTRAE IFORMACION DEL BUFFER DE TEXTO
    *  @param std::string
    **/
    void get_var(std::string &);
    /**
    *  @brief ESTRAE IFORMACION DEL BUFFER DE TEXTO
    *  @param double
    **/
    void get_var(double &);
    /**
    *  @brief ESTRAE IFORMACION DEL BUFFER DE TEXTO
    *  @param float
    **/
    void get_var(float &);

    /**
    *  @brief ESTRAE IFORMACION DEL BUFFER DE TEXTO
    *  @param int
    **/
    void get_var(int &);
    /**
    *  @brief RETORNA LA POCISION X DEL TEXTO
    *
    **/
    int const getx();
    /**
    *  @brief  RETORNA LA POCISION Y DEL TEXTO
    **/
    int const gety();
    /**
    *  RETORNA LA ULTIMA POCICION EN X EN LA
    *  QUE SE IMPRIMIO LA ULTIMA LETRA
    **/
    int const getw();
    /**
    *  @brief  RETORNA EL COLOR DEL TEXTO
    **/
    int const getcolor();
    /**
    * RETORNA LA ALTURA DE LA FUNETE ACTUAL
    **/
    int const get_ht();
    /**
    *  @brief CAMBIA EL COLOR DEL TEXTO
    *  @param se para el color en un numero entero
    *
    **/
    void setcolor(int);
    /**
    *  cambia el color de fondo de el texto por defecto es
    *  -1 que da trasparente
    *  @brief CAMBIA EL MODO DEL TEXTO
    *  @param se para el color en un numero entero
    **/
    void allmodo(int );
    /**
    *  cambia el color del puntero de texto
    *  @brief INGRESAR EL COLOR DEL PUNTERO
    *  @param color del puntero  entero
    **/
    void puntero_tex(int);
    /**
    *  carga una fuente pcx en el objeto para
    *  todo el teto impreso por este objto utilisara esta fuente
    *  amenos que se cambie
    *  @brief CARGA UNA FUENTE
    *  @param direccion de el fichero pcx
    **/
    void cargar_fuente(const char *);
    /**
    *  carga una fuente FONT* en el objeto para
    *  todo el teto impreso por este objto utilisara esta fuente
    *  amenos que se cambie
    *  @param un variable de tipo FONT*
    *  @brief CARGA UNA FUENTE
    **/
    void cargar_fuente(FONT *);
    /**
    *  cambia el bitmap en el que se imprime el texto
    *  por defecto es screen
    *  @brief CARGA UN BITMAP DE IMPRECION
    *  @param un bitmap y el color el segundo parametro es opcional
    **/
    void cargar_bitmap(BITMAP* ,int SETCOLO=-5);
    /**
    *  regresa el bitmap screen como bitmap de imprecion
    *  @brief REGRESA EL BITMAP screen
    *  @param El parametro es opcional
    **/
    void cargar_screen(int);
    /**
    *  @brief CAMBIA EL BITMAP DEL mouse_sprite
    *  @param bitmap de mouse
    *
    **/
    void cargar_mouse(BITMAP *&);

private:
    void COPY(ALLE_STREAM);
    void clear_buf();
    void get_key();
    void gotoxy(int,int);
    void set_iterador(const iterador &);
    void ln();
    const char *read_key();
    void write_screen(const char*);
    void puntero(BITMAP *);
    bool screen_p;
    int x_aux;
    int x_guar;
    int x,y;
    int color;
    int borrado;
    int ln_font;
    int limite;
    int punt_text;
    int timetic;
    FONT *fuente;
    BITMAP *pantalla;
    bool destruc;
    //var buffers
    alle_string string_buff;
};
/**
*  @brief SALTA UNA LINEA
**/
extern const ALLE_STREAM::iterador _endl;
/**
*  @brief SALTA DOS LINEA
**/
extern const ALLE_STREAM::iterador _endl2;
/**
*  LEE DINAMICAMENTE LA INFORMACION PROVENIENTE DEL TECLADO
*  Y LA GUARA EN EL BUFFER DE TEXTO
*  NO PARA EL BUCLE DONDE SE ENCUENTRE
*  @brief LECTURA DINAMICA
*
**/
extern const ALLE_STREAM::iterador _getkey;
/**
*  @brief BORRA EL BUFFER DE TEXTO
**/
extern const ALLE_STREAM::iterador _clearbuf;
/**
*  COORDENADAS DONDE SE IMPRIMIRA EL TEXTO SIGUIENTE
*  @brief CAMBIAR LAS COORDENADAS DEL TEXTO
*  @param X Y
**/
extern ALLE_STREAM::iterador _xy;
/**
*  @brief CAMBIA EL BITMAP DE IMPRECION
*  @param EL SEGUNDO PARAMETRO ES OPCIONAL
**/
extern ALLE_STREAM::iterador _bmp;
/**
*  longitud en pixeles maxima del texto  para las
*  funciones de entrada
*  @brief ESTABLECE LA LONGITUD EN PIXELES DEL TEXTO
**/
extern ALLE_STREAM::iterador _lmt;
/**
*  @brief OBJETO POR DEFECTO SE ALLE_STRING
**/
extern ALLE_STREAM iosall;

}

#endif // ALLE_STREAM_H
