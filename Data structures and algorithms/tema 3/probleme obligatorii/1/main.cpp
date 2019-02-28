#include <iostream>

using namespace std;

struct NOD
{
    int val;
    NOD *leg;
};

void Inserare(NOD* &cap, int valoare)
{
    NOD *a, *aux;
    a=cap;
    while(a->leg!=NULL && a->leg->val < valoare)
        a= a->leg;
    if(cap->val >= valoare)
    {
        aux->val=valoare;
        aux->leg=cap;
        cap=aux;
    }
    else
    {
        aux=new NOD;
        aux->val=valoare;
        aux->leg=a->leg;
        a->leg=aux;
    }
}

void Afisare(NOD* cap)
{
    while(cap!=NULL)
    {
        cout<<cap->val<<" ";
        cap= cap->leg;
    }
}

int main()
{
    int n, k;
    NOD *cap;
    cout<<"Introduceti numarul de valori pe care doriti sa le inserati: ";
    cin>>n;
    cout<<endl;
    cap=new NOD;
    cap->leg=NULL;
    cin>>cap->val;
    for(int i=2; i<=n; i++)
    {
        cin>>k;
        Inserare(cap,k);
    }
    Afisare(cap);
    return 0;
}
