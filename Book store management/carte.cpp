#include <iostream>
#include "carte.h"
#include <string.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

carte::carte()
{
    id = 0;
    an_aparitie = 0;
    nume_carte[0]='\0';
    nume_autor[0]='\0';
    pret = 0;
}

carte::~carte()
{
}

carte::carte(const carte& q)
{
    this->id = q.id;
    this->an_aparitie = q.an_aparitie;
    strcpy(this->nume_autor,q.nume_autor);
    strcpy(this->nume_carte,q.nume_carte);
    this->pret = q.pret;
}

int carte::getid()
{
    return id;
}

int carte::getAN()
{
    return an_aparitie;
}

int carte::comparareNume(char* c)
{
    if(stricmp(this->nume_carte,c)==0)
        return 1;
    else return 0;
}

void carte::modificare_carte()
{
    int x,ok=1;
    char q[50];
    double p;
    cout<<"\nIntroduceti noile valori";
    cout<<"\n\tID: ";
    do
    {
        ok=1;
        cin>>x;
    try
    {
    if(x<0) throw 1;
    id=x;
    }
    catch(int y)
    {
        if(y==1) cout<<"ID-ul nu poate fi negativ!\n\tIntroduceti un alt ID: ";
        ok=0;
    }
    }while(ok==0);
    cout<<"\n\tNumele cartii: ";
    getchar();
    gets(q);
    strcpy(nume_carte,q);
    cout<<"\n\tNumele autorului: ";
    gets(q);
    strcpy(nume_autor,q);
    cout<<"\n\tAnul aparitiei: ";
    do
    {
        ok=1;
        cin>>x;
    try
    {
    if(x<0) throw 1;
    else if(x>2017) throw 2;
    an_aparitie = x;
    }
    catch(int y)
    {
        if(y==1) cout<<"Anul aparitiei nu poate fi negativ!\n\tIntroduceti un alt an: ";
        else if(y==2) cout<<"Anul aparitiei nu poate fi mai mare decat 2017!\n\tIntroduceti un alt an: ";
        ok=0;
    }
    }while(ok==0);
    cout<<"\n\tPret: ";
    cin>>p;
    pret = p;
}

void carte::display()
{
    cout<<endl;
    cout<<"ID: "<<id<<endl;

    cout<<"Numele cartii: "<<nume_carte<<endl;
    cout<<"Numele autorului: "<<nume_autor<<endl;
    cout<<"Anul aparitiei: "<<an_aparitie<<endl;
    cout<<"Pret: "<<pret<<"RON\n";
}

ostream& operator << (ostream& out, carte c)
{
    out<<"\n_________________________________________________________________________\n";
    out<<"ID: "<<c.id<<endl;
    out<<"Numele cartii: "<<c.nume_carte<<endl;
    out<<"Numele autorului: "<<c.nume_autor<<endl;
    out<<"Anul aparitiei: "<<c.an_aparitie<<endl;
    out<<"Pret: "<<c.pret<<"RON\n";
    out<<"\n_________________________________________________________________________";
}

istream& operator >> (istream& in, carte& c)
{
    int ok=1;
    cout<<"\n\tIntroduceti ID-ul cartii: ";
    do
    {
        ok=1;
        in>>c.id;
    try
    {
    if(c.id<0) throw 1;
    }
    catch(int y)
    {
        if(y==1) cout<<"ID-ul nu poate fi negativ!\n\tIntroduceti un alt ID: ";
        ok=0;
    }
    }while(ok==0);
    cout<<"\n\tIntroduceti numele cartii: ";
    getchar();
    gets(c.nume_carte);
    cout<<"\n\tIntroduceti numele autorului: ";
    gets(c.nume_autor);
    cout<<"\n\tIntroduceti anul aparitiei: ";
    do
    {
        ok=1;
        in>>c.an_aparitie;
    try
    {
    if(c.an_aparitie<0) throw 1;
    else if(c.an_aparitie>2017) throw 2;
    }
    catch(int y)
    {
        if(y==1) cout<<"Anul aparitiei nu poate fi negativ!\n\tIntroduceti un alt an: ";
        else if(y==2) cout<<"Anul aparitiei nu poate fi mai mare decat 2017!\n\tIntroduceti un alt an: ";
        ok=0;
    }
    }while(ok==0);
    cout<<"\n\tIntroduce pretul: ";
    in>>c.pret;
    return in;
}

carte& carte::operator=(const carte &c)
{
    id=c.id;
    strcpy(this->nume_autor,c.nume_autor);
    strcpy(this->nume_carte,c.nume_carte);
    an_aparitie=c.an_aparitie;
    pret=c.pret;
}

