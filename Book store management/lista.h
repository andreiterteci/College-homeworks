#include <iostream>
#include <string.h>
#include "carte.h"

using namespace std;

template <class T>
class Vector
{
    T* *v;
    int nr;

public:
    Vector();
    Vector(int);
    ~Vector();

    void display();
    void add(T);
    void modificare(int);
    void stergere(int);
    void afisare_carte(int);
    int getNr();
};

template <class T>
Vector<T>::Vector()
{

    *v = new T;
    nr = 1;
}

template <class T>
Vector<T>::Vector(int n)
{
    nr = n;
    v = new T*[n];
    for (int i=0;i<n;++i)
        v[i]=new T;
}

template <class T>
Vector<T>::~Vector()
{
    for (int i=0;i<nr;++i)
        delete v[i];
    delete[] v;
}

template <class T>
void Vector<T>::display()
{
    cout<<"Lista cartilor disponibile:"<<endl;
    for(int i = 1 ; i < nr ; i++)
    {   cout<<"\n_________________________________________________________________________\n";
        v[i]->display();
        cout<<"\n_________________________________________________________________________\n";
    }

}

template <class T>
void Vector<T>::add(T x)
{
    try{
    T* *aux = new T*[nr+1];
    for(int i = 0 ; i < nr ; i++)
        aux[i] = v[i];

    aux[nr] = new T;
    (*aux[nr]) = x;

    nr++;

    delete[] v;

    v = new T*[nr];

    for(int i = 0 ; i < nr ; i++)
        v[i] = aux[i];

    delete[] aux;

    cout<<"Lista de carti a fost actualizata!"<<endl<<endl;
    }
    catch(bad_alloc& e)
    {
        cout<<"Memorie insuficienta!";
    }
}

template <class T>
void Vector<T>::stergere(int x)
{
    try{
    T* *aux = new T*[nr-1];

        for(int i = 0 ; i < x ; i++)
        aux[i] = v[i];

        for(int i = x+1 ; i < nr ; i++)
            aux[i-1] = v[i];

        nr--;

        delete[] v;

        v = new T*[nr];


    for(int i = 0 ; i < nr ; i++)
        v[i] = aux[i];

    delete[] aux;

    cout<<"Lista de carti a fost actualizata!"<<endl<<endl;
    }
    catch(bad_alloc& e)
    {
        cout<<"Memorie insuficienta!";
    }

}

template <class T>
void Vector<T>::afisare_carte(int x)
{
    v[x]->display();
    cout<<endl;
}

template <class T>
Vector<T>::getNr()
{
    return nr;
}

template <class T>
void Vector<T>::modificare(int x)
{
    v[x]->modificare_carte();
}
