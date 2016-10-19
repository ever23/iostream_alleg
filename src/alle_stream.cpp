/**
 * Name: CLASE ALLE_STREAM
 * Author: ENYERBER FRANCO
 * email: enyerverfranco@outlook.com
 * Date: 3/01/15 07:34
 * Description: DEFINICION DE LA CLASE PARA FLUJOS DE ENTRADA Y DE SALIDA DE TEXTO EN TECLADO Y PANTALLA
 * PARA ALLEGRO
**/
#include "../internal/alle_stream.hpp"
//**//
int bitmap_w(BITMAP *buff)
{
    return buff->w;
}
int bitmap_h(BITMAP *buff)
{
    return buff->h;
}

//contructor por defecto
all::ALLE_STREAM::ALLE_STREAM()
{
    screen_p=false;
    color=colordft;
    x=0;
    y=0;
    borrado=-1;
    x_aux=0;
    x_guar=0;
    limite=1360;
    fuente=font;
    ln_font=text_height(fuente);
    punt_text=0X0000;
    timetic=0;
    destruc=false;
}
all::ALLE_STREAM::ALLE_STREAM(const all::ALLE_STREAM &ALLE)
{
    COPY(ALLE);
   destruc=false;
}

all::ALLE_STREAM::ALLE_STREAM(int X,int Y,int COLOR,int FONDO)
{
    color=COLOR;
    borrado=FONDO;
    screen_p=false;
    gotoxy(X,Y);
    fuente=font;
    ln_font=text_height(fuente);
    limite=1360;
    punt_text=0X0000;
    timetic=0;
    destruc=false;
}

all::ALLE_STREAM::ALLE_STREAM(BITMAP *BMP_,int X,int Y,int COLOR,int FONDO)
{
    cargar_bitmap(BMP_,COLOR);
    color=COLOR;
    borrado=FONDO;
    gotoxy(X,Y);
    fuente=font;
    ln_font=text_height(fuente);
    punt_text=0X0000;
    limite=1360;

    timetic=0;
    destruc=false;
}

all::ALLE_STREAM::~ALLE_STREAM()
{
    if(!destruc)
    {
        if(fuente)
        delete fuente;
        if(pantalla)
        delete pantalla;
        _bmp.delete_();
        destruc=true;
    }
}

void all::ALLE_STREAM::COPY(all::ALLE_STREAM alle)
{
    screen_p=alle.screen_p;
    color=alle.color;
    x=alle.x;
    y=alle.y;
    borrado=alle.borrado;
    x_aux=alle.x_aux;
    x_guar=alle.x_guar;
    limite=alle.limite;
    fuente=alle.fuente;
    ln_font=alle.ln_font;
    pantalla=alle.pantalla;
    punt_text=alle.punt_text;
    fuente=alle.fuente;
}

void all::ALLE_STREAM::iostream_alleg_init(int X,int Y,int COLOR,int FONDO)
{
    color=COLOR;
    borrado=FONDO;
    gotoxy(X,Y);

}

void all::ALLE_STREAM::iostream_alleg_init(BITMAP *BMP_,int X,int Y,int COLOR,int FONDO)
{
    cargar_bitmap(BMP_,COLOR);
    borrado=FONDO;
    gotoxy(X,Y);
}



void all::ALLE_STREAM::cargar_fuente(const char *PCXMANE)
{
    if((fuente=load_font(PCXMANE,NULL,NULL))!=NULL)
    {
        ln_font=text_height(fuente);
    }else
    {
         allegro_message("   EL ARCHIVO %s NO EXISTE  ",PCXMANE);
         fuente=font;
        ln_font= text_height(fuente);
    }
}

void all::ALLE_STREAM::cargar_fuente(FONT *FUENTE)
{
    if(FUENTE!=NULL)
    {
        fuente= new FONT;
    fuente=FUENTE;
      ln_font= text_height(fuente);

    }else
    {
        allegro_message("   LA FUENTE CARGADA CONTIENE UN VALOR NULL  ");
        fuente=font;
         ln_font= text_height(fuente);
    }
}

//insertar coodenadas de texprintf
inline void all::ALLE_STREAM::gotoxy(int X,int Y)
{
    x=X;
    y=Y;
    x_aux=X;
    x_guar=X;
}

void all::ALLE_STREAM::setcolor(int COLOR)
{
    color=COLOR;
}

void all::ALLE_STREAM::allmodo(int COLOR)
{
    borrado=COLOR;

}

int const all::ALLE_STREAM::getx()
{
    return x;
}

int const all::ALLE_STREAM::gety()
{
     return y;
}

int const all::ALLE_STREAM::getcolor()
{
    return color;
}

int const all::ALLE_STREAM::getw()
{
    return x_guar;
}

int const all::ALLE_STREAM::get_ht()
{
    return text_height(fuente);
}

void all::ALLE_STREAM::cargar_bitmap(BITMAP *BMP_,int SETCOLO)
{
    if(BMP_!=NULL)
    {
        pantalla=create_sub_bitmap(BMP_, 0, 0,bitmap_w(BMP_) ,bitmap_h(BMP_));
        screen_p=true;
    }else
    {
        screen_p=false;
    }
    if(SETCOLO!=-5)
     color=SETCOLO;


}

void all::ALLE_STREAM::cargar_screen(int SETCOLOR)
{
    color=SETCOLOR;
    screen_p=false;
}

void all::ALLE_STREAM::puntero_tex(int COLOR)
{
    punt_text=COLOR;
}

void all::ALLE_STREAM::puntero(BITMAP *BMP_)
{
    if(timetic==0)
    {
        vline(BMP_,x_aux,y-2,y+text_height(fuente)+4,punt_text);
        vline(BMP_,x_aux+1,y-2,y+text_height(fuente)+4,punt_text);
    }
    timetic++;
    if(timetic>35)timetic=0;

}


inline void all::ALLE_STREAM::set_iterador(const iterador &INTE)
{
    switch(INTE.INTER)
    {
    case _ALLE_ENDL_:
        {
            ln();
            break;
        }
    case _ALLE_ENDL2_:
        {
             ln();ln();
             break;
        }
    case _ALLE_GETKEY_:
        {
            get_key();
            break;
        }
    case _ALLE_CLEARBUF_:
        {
            clear_buf();
            break;
        }
    case _ALLE_XY_:
        {
             gotoxy(INTE.x_i,INTE.y_i);
             break;
        }
    case _ALLE_BMP_:
        {
            cargar_bitmap(INTE.bitmap_i,INTE.color_i);
            break;
        }
    case _ALLE_LMT_:
        {
            limite=INTE.lmt;
            break;
        }
    default :
         allegro_message("ERROR SOLO SE ACEPTAN INTERADORE \n ENDL ENDL2 GETKEY CLEARBUFF XY() Y BMP() ");
        break;
    }
}
inline void all::ALLE_STREAM::ln()
{
    y+=ln_font;
    x_guar=x;
    x_aux=x;
}


void all::ALLE_STREAM::cargar_mouse(BITMAP *&MOUSE)
{
    install_mouse();
    set_mouse_sprite(MOUSE);
}

void all::ALLE_STREAM::clear_buf()
{
    string_buff.clear();
}


void all::ALLE_STREAM::set_stringbuff(const char *cadena)
{
    string_buff=cadena;
}


void all::ALLE_STREAM::get_key()
{

    if(keypressed())
    {
        char lt=readkey();
        if((lt>=32 && lt<=174 ) && (text_length(fuente, string_buff)<limite) )
        {
            string_buff+=lt;

        }
        if(lt==8 && string_buff.getn()>0)
        {
            string_buff--;
        }
    }
    x_aux=x_guar+text_length(fuente, string_buff);
    if(screen_p)
    {
        textout_ex(pantalla, fuente, string_buff, x_guar, y, color, borrado);
        puntero(pantalla);
    }
    else
    {
        textout_ex(screen, fuente, string_buff, x_guar, y, color, borrado);
        puntero(screen);
    }
}


void all::ALLE_STREAM::get_var(char &caracter)
{
    for(int i=0;i<string_buff.getn();i++)
    {
        if(string_buff[i]!=' ')
        {
             caracter=string_buff[i]; break;
        }
    }
    clear_buf();
}

void all::ALLE_STREAM::get_var(char cadena[])
{

    strcpy(cadena, string_buff);
}

void all::ALLE_STREAM::get_var(alle_string &cadena)
{
    cadena=string_buff;
}

void all::ALLE_STREAM::get_var(std::string &cadena)
{
    cadena.clear();
    cadena=string_buff;
}

void all::ALLE_STREAM::get_var(float &flotante)
{
    flotante=atof(string_buff);
}

void all::ALLE_STREAM::get_var(double &flotante)
{
    flotante=atof(string_buff);
}

void all::ALLE_STREAM::get_var(int &entero)
{
    entero=atoi(string_buff);
}


const char *all::ALLE_STREAM::read_key()
{
    bool prin_mouse=false;
    if(install_mouse())
    {
        remove_mouse();
        prin_mouse=false;
    }
    else
    {
        prin_mouse=true;
    }
    clear_keybuf();
    BITMAP **SUBSCREN=new BITMAP*;
    if(screen_p)
    {
        *SUBSCREN = create_bitmap(bitmap_w(pantalla) ,bitmap_h(pantalla));
        blit(pantalla,*SUBSCREN, 0, 0, 0, 0, bitmap_w(pantalla) ,bitmap_h(pantalla));
    }
    else
    {
        *SUBSCREN = create_bitmap(bitmap_w(screen) ,bitmap_h(screen));
        pantalla = create_bitmap(bitmap_w(screen) ,bitmap_h(screen));
        blit(screen,*SUBSCREN, 0, 0, 0, 0, bitmap_w(screen) ,bitmap_h(screen));
        blit(*SUBSCREN,pantalla, 0, 0, 0, 0, bitmap_w(screen) ,bitmap_h(screen));
    }

    int n=0;
    clear_buf();
    do
    {

        get_key();
        if(prin_mouse)
        {
            draw_sprite(pantalla,mouse_sprite,mouse_x,mouse_y);
        }
        if(screen_p)
        {
            blit(pantalla,screen, 0, 0,0 ,0 , bitmap_w(pantalla) ,bitmap_h(pantalla));
            draw_sprite(pantalla,*SUBSCREN, 0, 0);
        }
        rest(5);
    }
    while( !key[KEY_ENTER] && !key[KEY_ENTER_PAD] /*lt!=13*/ && n<MAX_CADENA);
    key[KEY_ENTER]=false;
    key[KEY_ENTER_PAD]=false;
    clear_to_color(*SUBSCREN,1);
    destroy_bitmap(*SUBSCREN);
    delete SUBSCREN;
    return string_buff;
}

void  all::ALLE_STREAM::operator ()(int X,int Y,const iterador &a)
{
    gotoxy(X,Y);
    set_iterador(a);
}

void  all::ALLE_STREAM::operator ()(int X,int Y,char &caracter)
{
    gotoxy(X,Y);
    const char *aux;
    aux=read_key();
    int n=strlen(aux);
   for(int i=0;i<n;i++)
    {
        if(aux[i]!=' ')
        {
             caracter=aux[i]; break;
        }
    }
    delete [] aux;
   clear_buf();
}
void  all::ALLE_STREAM::operator ()(int X,int Y,char *&cadena)
{
    gotoxy(X,Y);
    const char *c=read_key();
    int n=strlen(c);
    cadena = new char[ n + 1 ];
    strcpy(cadena, c);
    clear_buf();

}
void  all::ALLE_STREAM::operator ()(int X,int Y,char cadena[])
{
    gotoxy(X,Y);
    strcpy(cadena, read_key());
    clear_buf();
}

void  all::ALLE_STREAM::operator ()(int X,int Y,alle_string &cadena)
{
    gotoxy(X,Y);
    cadena=read_key();
    clear_buf();
}

void  all::ALLE_STREAM::operator ()(int X,int Y,std::string &cadena)
{
    gotoxy(X,Y);
    cadena.clear();
    cadena=read_key();
}

void  all::ALLE_STREAM::operator ()(int X,int Y,float &entero)
{
    gotoxy(X,Y);
    //convertir de cadena a _float funcion de windons.h y q tambien la contiene allegro
    entero=atof(read_key());
     clear_buf();
}

void  all::ALLE_STREAM::operator ()(int X,int Y,double &entero)
{
    gotoxy(X,Y);
    //convertir de cadena a entero funcion de windons.h y q tambien la contiene allegro
    entero=atof(read_key());
     clear_buf();
}

void  all::ALLE_STREAM::operator ()(int X,int Y,int &entero)
{
    gotoxy(X,Y);
    //convertir de cadena a entero funcion de windons.h y q tambien la contiene allegro
    entero=atoi(read_key());
     clear_buf();
   // delete getstring;
}

//FLUJOS DE ENTRADA/*

all::ALLE_STREAM  &all::ALLE_STREAM::operator >>(char &caracter)
{
    const char *aux;
    aux=read_key();
    int n=strlen(aux);
    for(int i=0;i<n;i++)
    {
        if(aux[i]!=' ')
        {
             caracter=aux[i]; break;
        }
    }
    delete [] aux;
     clear_buf();

    return *this;
}

all::ALLE_STREAM  &all::ALLE_STREAM::operator >>(char *&cadena)
{

    const char *c=read_key();
    int n=strlen(c);
    cadena = new char[ n + 1 ];
    strcpy(cadena, c);
     clear_buf();
    return *this;
}
all::ALLE_STREAM  &all::ALLE_STREAM::operator >>(char cadena[])
{
     strcpy(cadena, read_key());
      clear_buf();
    return *this;
}
all::ALLE_STREAM  &all::ALLE_STREAM::operator >>(alle_string &cadena)
{

    cadena=read_key();
     clear_buf();
    return *this;
}

all::ALLE_STREAM  &all::ALLE_STREAM::operator >>(std::string &cadena)
{
    cadena.clear();
    cadena=read_key();
     clear_buf();
    return *this;

}

all::ALLE_STREAM  &all::ALLE_STREAM::operator >>(float &_float)
{
    //convertir de cadena a _float funcion de windons.h y q tambien la contiene allegro
    _float=atof(read_key());
     clear_buf();
    return *this;

}

all::ALLE_STREAM  &all::ALLE_STREAM::operator >>(double &_double)
{
    //convertir de cadena a _double funcion de windons.h y q tambien la contiene allegro
    _double=atof(read_key());
     clear_buf();
    return *this;

}

all::ALLE_STREAM  &all::ALLE_STREAM::operator >>(int &entero)
{
    //convertir de cadena a entero funcion de windons.h y q tambien la contiene allegro
    entero=atoi(read_key());
     clear_buf();
    return *this;
}

//FLUJOS DE SALIDA
inline void all::ALLE_STREAM::write_screen(const char *cadena)
{
    if(cadena!=NULL)
    {
        if(screen_p)
        {
            textout_ex(pantalla, fuente, cadena, x_aux, y, color, borrado);
        }
        else if(!screen_p)
        {
            textout_ex(screen, fuente, cadena, x_aux, y, color, borrado);
        }
        x_aux=x_guar+text_length(fuente, cadena);
        x_guar=x_aux+text_length(fuente, " ");
    }
}

all::ALLE_STREAM  &all::ALLE_STREAM::operator<<(const iterador &INTE)
{
    set_iterador(INTE);
    return *this;
}

all::ALLE_STREAM &all::ALLE_STREAM::operator<<(alle_string text)
{
    write_screen(text);
    return *this;
}
all::ALLE_STREAM &all::ALLE_STREAM::operator<<(char text)
{
    char *aux= new char[2];
    aux[0]=text;
    aux[1]='\0';
    write_screen(aux);
    delete [] aux;
    return *this;
}

all::ALLE_STREAM &all::ALLE_STREAM::operator<<(const char *text)
{
    write_screen(text);
    return *this;
}

all::ALLE_STREAM &all::ALLE_STREAM::operator<<(std::string text)
{
    write_screen(text.c_str());
    return *this;
}

all::ALLE_STREAM &all::ALLE_STREAM::operator<<(float flotante)
{
    write_screen(num_cadena(flotante));
    return *this;
}

all::ALLE_STREAM &all::ALLE_STREAM::operator<<(int entero)
{
    write_screen(num_cadena(entero));
    return *this;
}
all::ALLE_STREAM &all::ALLE_STREAM::operator<<(double flotante)
{
    write_screen(num_cadena(flotante));
    return *this;
}
void all::ALLE_STREAM::iterador::delete_()
{
    if(bitmap_i)
    {
         delete bitmap_i;
    }

}

all::ALLE_STREAM::iterador all::ALLE_STREAM::iterador::operator()(int X,int Y)
{
    if(INTER==_ALLE_XY_)
    {
        x_i=X;
        y_i=Y;
    }else
    {
         allegro_message("ERROR UTILISE XY(%i,%i) PARA ESTA OPERACION",X,Y);
    }

    return *this;
}

all::ALLE_STREAM::iterador all::ALLE_STREAM::iterador::operator()(BITMAP *BMP_,int COLOR)
{
    if(INTER==_ALLE_BMP_)
    {
        bitmap_i=create_sub_bitmap(BMP_, 0, 0,bitmap_w(BMP_) , bitmap_h(BMP_));
        color_i=COLOR;
    }else
    {
         allegro_message("ERROR UTILISE  BMP(BITMAP *,  int) PARA ESTA OPERACION");
    }
   return *this;
}

all::ALLE_STREAM::iterador all::ALLE_STREAM::iterador::operator()(int lmt)
{
    if(INTER==_ALLE_LMT_)
    {
        this->lmt=lmt;
    }else
    {
         allegro_message("ERROR UTILISE LMT(int ) ");
    }
   return *this;
}


all::ALLE_STREAM::iterador::~iterador()
{

}

const all::ALLE_STREAM::iterador all::_endl(_ALLE_ENDL_);

const all::ALLE_STREAM::iterador all::_endl2(_ALLE_ENDL2_);

const all::ALLE_STREAM::iterador all::_getkey(_ALLE_GETKEY_);

const all::ALLE_STREAM::iterador all::_clearbuf(_ALLE_CLEARBUF_);

all::ALLE_STREAM::iterador all::_xy(_ALLE_XY_);
all::ALLE_STREAM::iterador all::_bmp(_ALLE_BMP_);
all::ALLE_STREAM::iterador all::_lmt(_ALLE_LMT_);

all::ALLE_STREAM all::iosall;





