#include <iostream>
#include <math.h>

using namespace std;

struct pol
{
    int grad,coef;
    pol *next;
};

void Inserare(pol* &cap, int x, int y)
{
    pol *a, *aux;
    a=cap;
    while(a->next!=NULL && a->next->grad < x)
        a= a->next;
    if(cap->grad >= x)
    {
        aux->grad=x;
        aux->coef=y;
        aux->next=cap;
        cap=aux;
    }
    else
    {
        aux=new pol;
        aux->grad=x;
        aux->coef=y;
        aux->next=a->next;
        a->next=aux;
    }
}

void Afisare(pol* cap)
{
    while(cap!=NULL)
    {
        cout<<cap->coef<<"X^"<<cap->grad<<" ";
        cap= cap->next;
    }
}

void inmultire(pol* &p, int a)
{
    pol *b;
    b=p;
    while(b!=NULL)
    {
        b->coef*=a;
        b=b->next;
    }
}

int p0(pol* p, int w)
{
    pol* a;
    a=p;
    int s=0;
    while(a!=NULL)
    {
        s+=pow(w,a->grad)*a->coef;
        a=a->next;
    }
    return s;
}

void suma(pol* &p, pol* &q)
{
    pol *a,*b;
    a=q;
    b=p;
    while(a!=NULL && b!=NULL)
    {
        if(a->grad==b->grad)
        {
            cout<<a->coef+b->coef<<"X^"<<a->grad;
            a=a->next;
            b=b->next;
        }
        else if(a->grad > b->grad)

    }
}

int main()
{
    int n,m,a,k,z,w;
    pol *p,*q,*c;
    cout<<"Introduceti numarul de valori pe care doriti sa le inserati: ";
    cin>>n;
    cout<<endl;
    p=new pol;
    p->next=NULL;
    q=new pol;
    q->next=NULL;
    cout<<"Introduceti coeficientul si gradul fiecarui element pentru polinomul p: "<<endl;
    cin>>p->coef>>p->grad;
    for(int i=2; i<=n; i++)
    {
        cin>>k>>z;
        Inserare(p,z,k);
    }
    cout<<"Introduceti coeficientul si gradul fiecarui element pentru polinomul q: "<<endl;
    cin>>q->coef>>q->grad;
    for(int i=2; i<=n; i++)
    {
        cin>>k>>z;
        Inserare(q,z,k);
    }
//    cout<<"Introduceti scalarul: ";
//    cin>>a;
//    cout<<endl;
//    inmultire(p,a);
//    cout<<"Introduceti punctul x0: ";
//    cin>>w;
//    cout<<p0(p,w)<<endl;
    suma(p,q,c);
    Afisare(c);
    return 0;
}
