#include <iostream>

using namespace std;

bool empty(int* stiva,int vf)
{
    if(vf==-1) return true;
    else return false;
}

void push(int a, int* &stiva, int &vf)
{
    stiva[++vf]=a;
}

int pop(int* &stiva, int &vf)
{
    if(empty(stiva,vf)) cout<<"Stiva este vida!"<<endl;
    else return stiva[vf--];
}

int peek(int* stiva, int vf)
{
    return stiva[vf];
}



int search(int a, int* &stiva, int &vf)
{
    int *aux, nr=0,i=-1,ok=0;
    aux = new int[vf];
    while(empty(stiva,vf)==false && ok!=1)
    {
        if(peek(stiva,vf)==a) ok=1;
        else
        {
            push(pop(stiva,vf),aux,i);
            nr++;
        }
    }
    push(pop(aux,i),stiva,vf);
    delete []aux;
    if(ok==0) return -1;
    return nr;
}

void afiseaza(int* stiva,int vf)
{
    while(empty(stiva,vf)==false)
        cout<<pop(stiva, vf)<<" ";
}

int main()
{
    int a,x,n, *stiva, vf, i, vfa, vfb;
cout<<"Dimensiunea maxima a stivei: ";
cin>>n;
stiva = new int[n];
vf = -1;

cout<<endl<<"Numarul de elemente pe care doriti sa le introduceti in stiva: ";
cin>>x;
cout<<endl<<"Introduceti elementele: ";
for(i=0;i<x;i++)
    {
        cin>>a;
        if(vf==n) {cout<<"Stiva este plina!";break;}
    else push(a,stiva,vf);
    }
cout<<pop(stiva,vf);
cout<<peek(stiva,vf);
cout<<empty(stiva,vf);
cout<<"Elementul cautat: ";
cin>>k;
cout<<search(k,stiva,vf);
afiseaza(stiva,vf);

//problema 2

//    char w[200];
//    int k;
//    int *stivaa, *stivab;
//    cout<<"Dimensiunea maxima a stivei: ";
//    cin>>n;
//    stivaa = new int[n];
//    stivab = new int[n];
//    vfa=vfb=-1;
//    cout<<endl<<"Dimensiunea vectorului w: ";
//    cin>>k;
//    for(int j=0; j<k; j++)
//    {
//        cin>>w[j];
//        if(w[j]=='a') push(1, stivaa, vfa);
//        else push(2,stivab,vfb);
//    }
//    while(empty(stivaa,vfa)==false  || empty(stivab,vfb)== false)
//    {
//        pop(stivaa,vfa);
//        pop(stivab,vfb);
//    }
//
//    if(empty(stivaa,vfa)== true && empty(stivab, vfb)==true)
//        cout<<"Numarul de caractere 'a' este egal cu numarul de caractere 'b'";
//    else cout<<"Numarul de caractere 'a' nu este egal cu numarul de caractere 'b'";


    //problema 3
char w[200];
char k;
cout<<"Dimensiunea maxima a stivei: ";
cin>>n;
stiva = new int[n];
vf = -1;
int nr1=0,nr2=0;
cout<<endl<<"Introduceti numarul de paranteze: ";
cin>>x;
for(i=0;i<x;i++)
{
    cin>>k;
    if(k=='(')
    push(1,stiva,vf);
    else push(2,stiva,vf);
    if(peek(stiva,vf)==1) nr1++;
    else nr2++;
    if(nr2>nr1) {cout<<endl<<"Sirul nu este corect parantezat";break;}
}
    if(nr2==nr1) cout<<endl<<"Sirul este corect parantezat";

    return 0;
}
