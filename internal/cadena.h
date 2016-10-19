/**
 * Name: cadena
 * Author: ENYERBER FRANCO
 * email: enyerverfranco@outlook.com
 * Date: 3/01/15 07:34
 * Description: declaracion de la clase cadena
**/

#ifndef CADENA_H
#define CADENA_H
#define MAX_CADENA 500

#include <iostream>
#include <string.h>
#include <sstream>
/**
*  @brief CONVIERTE UN NUMERO EN UNA CADENA DE TEXTO
*  @param el parametro puede ser int float double
**/
template <class NUMERIC>
const char *num_cadena(NUMERIC num)
{
    std::stringstream stream_buf;
    std::string retorno;
    stream_buf<<num;
    retorno=stream_buf.str();
    return  retorno.c_str();
}
/**
*  @brief CLASE CADENA PARA MANEJAR CADENAS DE TEXTO
**/
typedef class CADENA
{
public:
    CADENA(); // constructor por defecto
    CADENA(const char*); // constructor general
    CADENA(char); // constructor general
    CADENA(const CADENA&); // constructor de copia
    CADENA(int ); //crea un arreglo string de n
    ~CADENA(); // destructor
    /**
    *  @brief INSERTA UNA CADENA EN EL OBJETO
    *  @param cadena de texto
    **/
    void setcad(const char*);
    /**
    *  @brief RETORNA EL TAMAÑO DE LA CADENA
    *
    **/

    int const getn();
    /**
    *   @brief CONVIERTE UN NUMERO EN CADENA DE TEXTO
    *   @param el parametro puede ser int float double
    *   CONVIERTE EL NUMERO EN CADENA Y LA INSERTA EN EL OBJETO
    **/
    template <class NUMERIC>
    void setnum (const NUMERIC &num)
    {
        const char *cd= num_cadena(num);
        if(pstr != cd)
        {
            n = strlen(cd);
            delete [] pstr;
            pstr = new char[n + 1];
            strcpy(pstr, cd);
        }
    }
     /**
    *   @brief CONVIERTE UN NUMERO EN CADENA DE TEXTO
    *   @param el parametro puede ser int float double
    *   CONVIERTE EL NUMERO EN CADENA Y LA INSERTA EN EL OBJETO
    *   UTILISANDO EL OPERADOR DE TRASFERENCIA
    **/
    template <class NUMERIC>
    void operator<<(const NUMERIC &num)
    {
        setnum(num);
    }
    void clear();
    // sobrecarga de operadores
    CADENA& operator= (const CADENA&);
    CADENA& operator= (const char *);
    CADENA& operator= ( char []);
    CADENA& operator= (char);
    CADENA& operator= (std::string);

    friend CADENA operator+ (const CADENA&, const CADENA&);
    friend CADENA operator+ (const CADENA&, const char* );
    friend CADENA operator+ (const char*, const CADENA&);
    friend CADENA operator+ (std::string, const CADENA&);
    friend CADENA operator+ (const CADENA&, std::string);
    //concatenacion
    void operator+=(CADENA &cad);
    void operator+= (const char* );
    void operator+= (std::string);
    void operator+= (char);
    //elimina el ultimo caracter de la cadena
    CADENA operator-- (int);
    //comparacion
    friend int operator== (const CADENA&, const CADENA&);
    friend int operator== (const char*, const CADENA&);
    friend int operator== (const CADENA&,const char*);
    friend int operator== (const CADENA&,std::string);
    friend int operator== (std::string, const CADENA&);

    friend int operator!= (const CADENA&, const CADENA&);
    friend int operator!= (const CADENA&, const char*);
    friend int operator!= (const char*, const CADENA&);
    friend int operator!= (const CADENA&, std::string);
    friend int operator!= (std::string, const CADENA&);
    // llamada retorna la cadena
    const char *operator() ();
    //indexacion
    char operator[] (int i);
    //operador unitario
    operator const char *();

    //flujos para entrada y salida estandar iostream
    friend std::ostream& operator<< (std::ostream&, const CADENA&);
    friend std::istream& operator>> (std::istream&, CADENA&);

private:
    char* pstr;
    int n; // nº de caracteres

} alle_string;

#endif // CADENA_H
