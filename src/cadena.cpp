/**
 * Name: cadena
 * Author: ENYERBER FRANCO
 * email: enyerverfranco@outlook.com
 * Date: 3/01/15 07:34
 * Description: definicion de la clase cadena y la sobrecarga de operadores
**/

#include "../internal/cadena.hpp"
// constructor por defecto
CADENA::CADENA()
{
    pstr = new char[1];
    strcpy(pstr, "");
    n = 0;
}

// constructor general
CADENA::CADENA(const char* c)
{
    n = strlen(c);
    pstr = new char[n + 1];
    strcpy(pstr, c);
}

CADENA::CADENA(char c)
{
    pstr = new char[2];
    pstr[0]=c;
    pstr[1]=0;
}
// constructor de copia
CADENA::CADENA(const CADENA& cd)
{
    n = cd.n;
    pstr = new char[n + 1];
    strcpy(pstr, cd.pstr);
}

CADENA::CADENA(int i)
{
    pstr = new char[i];
    strcpy(pstr, "");
    n = i;
}
// destructor
CADENA::~CADENA()
{
    if(pstr!=NULL)
        delete [] pstr;
}

int const CADENA::getn()
{
    return n;
}
// función miembro setcad()
void CADENA::setcad(const char* c)
{
    n = strlen(c);
    delete [] pstr;
    pstr = new char[n+1];
    strcpy(pstr, c);


}
void CADENA::clear()
{
    delete [] pstr;
    pstr = new char[1];
    strcpy(pstr, "");
    n = 0;
}
// operador de asignación sobrecargado (=)
CADENA& CADENA::operator= (const CADENA& cd)
{
    if(*this != cd)
    {
        n = cd.n;

        delete [] pstr;
        pstr = new char[n + 1];
        strcpy(pstr, cd.pstr);
    }
    return *this;
}

CADENA& CADENA::operator= (char c)
{
    delete [] pstr;
    pstr = new char[2];
    pstr[0]=c;
    pstr[1]=0;

    return *this;
}

CADENA& CADENA::operator= (const char *cd)
{
    setcad(cd);
    return *this;
}

CADENA& CADENA::operator= (char cadena[])
{
    setcad(cadena);
    return *this;
}

CADENA& CADENA::operator= (std::string cd)
{
    if(pstr != cd.c_str())
    {
        setcad(cd.c_str());
    }
    return *this;
}

void CADENA::operator+=(CADENA &cad)
{
    int naux= n + cad.n;
    CADENA aux(pstr);
    delete [] pstr;
    pstr =  new char[naux + 1];
    strcpy(pstr, aux.pstr);
    strcat(pstr, cad.pstr);
    n=naux;
}
void CADENA::operator+=(const char *cad)
{
    int naux= n + strlen(cad);
    CADENA aux(pstr);
    delete [] pstr;
    pstr =  new char[naux + 1];
    strcpy(pstr, aux.pstr);
    strcat(pstr, cad);
    n=naux;
}

void CADENA::operator+=(std::string cad)
{
    int naux= n + strlen(cad.c_str());
    CADENA aux(pstr);
    delete [] pstr;
    pstr =  new char[naux + 1];
    strcpy(pstr, aux.pstr);
    strcat(pstr, cad.c_str());
    n=naux;
}

void CADENA::operator+=(char cad)
{
    char au[n],a[2];
    strcpy(au, pstr);
    delete [] pstr;
    try
    {
        pstr=new char[n+2];
        strcpy(pstr, au);
        a[0]=cad;
        a[1]='\0';
        strcat(pstr,a);
        n++;
    }
    catch(std::bad_alloc&)
    {
        std::cout<<" ERROR DE MEMORIA "<<std::endl;
    }
}


CADENA CADENA::operator--(int)
{
    char au[n];
    if(n>0)
    {
        n--;
        pstr[n]='\0';
        strcpy(au, pstr);
        delete [] pstr;
    try
    {

        pstr=new char[n+1];
        strcpy(pstr,au);
    }
    catch(std::bad_alloc& )
    {
        std::cout<<" ERROR DE MEMORIA "<<std::endl;
    }

    }
    return *this;
}

char CADENA::operator[](int i)
{
    char a=' ';
    if(i<=n)
        a=pstr[i];
    return a;
}
const char *CADENA::operator() ()
{
    return pstr;
}

CADENA::operator const char *()
{
    try
    {
       return pstr;
    }
    catch(std::bad_alloc&)
    {
        std::cout<<" ERROR DE MEMORIA "<<std::endl;
    }
    return " ";
}

// operador de flujo en ostream
std::ostream& operator<< (std::ostream& cout_, const CADENA& cad)
{
    cout_ << cad.pstr;
    return cout_;
}
//operador de flujo en istream
std::istream& operator>> (std::istream& cin_, CADENA& cad)
{
    cin_ >> cad.pstr;
    cad.n=strlen(cad.pstr);
    return cin_;
}

CADENA operator+ (const CADENA& a, const CADENA& b)
{
    CADENA c;
    c.n = a.n + b.n;
    c.pstr = new char[c.n + 1];
    strcpy(c.pstr, a.pstr);
    strcat(c.pstr, b.pstr);
    return c;
}

CADENA operator+ (const CADENA& a, const char* ch)
{
    CADENA c;
    c.n = a.n + strlen(ch);
    c.pstr = new char[c.n + 1];
    strcpy(c.pstr, a.pstr);
    strcat(c.pstr, ch);
    return c;
}
CADENA operator+ (const char* ch, const CADENA& b)
{
    CADENA c;
    c.n = strlen(ch) + b.n;
    c.pstr = new char[c.n + 1];
    strcpy(c.pstr, ch);
    strcat(c.pstr, b.pstr);
    return c;
}

CADENA operator+ (std::string ch, const CADENA& b)
{
    CADENA c;
    c.n = strlen(ch.c_str()) + b.n;
    c.pstr = new char[c.n + 1];
    strcpy(c.pstr, ch.c_str());
    strcat(c.pstr, b.pstr);
    return c;
}

CADENA operator+ (const CADENA& a, std::string ch )
{
    CADENA c;
    c.n = a.n + strlen(ch.c_str());
    c.pstr = new char[c.n + 1];
    strcpy(c.pstr, a.pstr);
    strcat(c.pstr, ch.c_str());
    return c;
}




// sobrecarga de los operadores relacionales
int operator== (const CADENA& c1, const CADENA& c2)
{
    if(strcmp(c1.pstr, c2.pstr)==0)
        return 1;
    return 0;
}

int operator== (const char* c1, const CADENA& c2)
{
    if(strcmp(c1, c2.pstr)==0)
        return 1;
    return 0;
}

int operator== (const CADENA& c1, const char* c2)
{
    if(strcmp(c1.pstr, c2)==0)
        return 1;
    return 0;
}

int operator== (std::string c1, const CADENA& c2)
{
    if(strcmp(c1.c_str(), c2.pstr)==0)
        return 1;
    return 0;
}

int operator== (const CADENA& c1, std::string c2)
{
    if(strcmp(c1.pstr, c2.c_str())==0)
        return 1;
    return 0;
}
int operator!= (const CADENA& c1, const CADENA& c2)
{
    int dif = strcmp(c1.pstr, c2.pstr);
    if(dif<0)
        return (-1);
    if(dif==0)
        return 0;
    else
        return 1;
}
int operator!= (const char* c1, const CADENA& c2)
{
    int dif = strcmp(c1, c2.pstr);
    if(dif<0)
        return (-1);
    if(dif==0)
        return 0;
    else
        return 1;
}

int operator!= (const CADENA& c1, const char* c2)
{
    int dif = strcmp(c1.pstr, c2);
    if(dif<0)
        return (-1);
    if(dif==0)
        return 0;
    else
        return 1;
}

int operator!= (std::string c1, const CADENA& c2)
{
    int dif = strcmp(c1.c_str(), c2.pstr);
    if(dif<0)
        return (-1);
    if(dif==0)
        return 0;
    else
        return 1;
}

int operator!= (const CADENA& c1, std::string c2)
{
    int dif = strcmp(c1.pstr, c2.c_str());
    if(dif<0)
        return (-1);
    if(dif==0)
        return 0;
    else
        return 1;
}

// fin del fichero CADENA.cpp










