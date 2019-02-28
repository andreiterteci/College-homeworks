#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

#ifndef CARTE_H
#define CARTE_H

class carte
{
public:
    int id, an_aparitie;
    char nume_autor[50];
    char nume_carte[50];
    double pret;
    carte();
    carte(int x, int q, char* y, char* z, double k)
    {
        id = x;
        an_aparitie = q;
        strcpy(nume_carte,y);
        strcpy(nume_autor,z);
        pret = k;
    }
    ~carte();
    carte(const carte&);
    void modificare_carte();
    void display();
    int getid();
    int getAN();
    int comparareNume(char*);
    friend ostream& operator << (ostream&, carte);
    friend istream& operator >> (istream&, carte&);
    carte& operator = (const carte&);
};

#endif
