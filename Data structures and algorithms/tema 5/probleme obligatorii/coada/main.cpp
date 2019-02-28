#include <iostream>

using namespace std;

void push(int a, int* &coada, int &sf)
{
    coada[++sf]=a;
}

int pop(int* &coada, int &inc, int sf)
{
    if(inc>sf) cout<<"Coada este vida!";
    else return coada[inc++];
}

int peek(int* coada, int inc, int sf)
{
    if(inc>sf) cout<<"Coada este vida!";
    else return coada[inc];
}

bool empty(int* coada, int inc, int sf)
{
    if(inc > sf) return true;
    else return false;
}

int search(int a, int* &coada, int &inc, int &sf)
{
    int *aux, nr=0,i=-1,j=0,ok=0;
    aux = new int[sf];
    while(empty(coada,inc,sf)==false && ok!=1)
    {
        if(peek(coada,inc,sf)==a) ok=1;
            else {push(pop(coada,inc,sf),aux,i);nr++;}
    }
    while(empty(coada,inc,sf)==false)
        push(pop(coada,inc,sf),aux,i);
    while(empty(aux,j,i)==false)
        push(pop(aux,j,i),coada,sf);
    delete []aux;
    if(ok==0) return -1;
    return nr;
}

void afisare(int* coada, int inc, int sf)
{
    while(empty(coada,inc,sf)==false)
        cout<<endl<<pop(coada,inc,sf)<<" ";
}

int main()
{
    int *coada, n, x, inc=0, sf=-1, k, z;
    cout<<"Introduceti dimensiunea maxima a cozii: ";
    cin>>n;
    coada = new int[n];
    cout<<endl<<"Introduceti numarul de elemente pe care doriti sa le inserati in coada: ";
    cin>>x;
    cout<<endl<<"Introduceti elemntele: ";
    for(int i=0;i<x;i++)
    {
        cin>>k;
        if(sf == n) cout<<endl<<"Coada este plina!";
        else push(k,coada,sf);
    }
    cout<<search(1,coada,inc,sf);

    afisare(coada,inc,sf);

    return 0;
}
