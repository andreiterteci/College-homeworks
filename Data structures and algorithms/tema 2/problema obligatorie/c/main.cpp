#include <iostream>

using namespace std;

struct NOD
{
    int val;
    NOD *leg;
};

void InserareInceput(NOD* &cap)
{
    NOD* elem = new NOD;
    cin>>elem->val;
    elem->leg = cap;
    cap = elem;
}

void InserareDupa (NOD* &cap, int valoare)
{
    NOD* c;
    NOD *a;
    c = cap;
    while(c->val!=valoare && c)
        c=c->leg;
    a = new NOD;
    cout<<"Valoarea de inserat: ";
    cin>>a->val;
    a->leg = c->leg;
    c->leg = a;
}

void InserareInainte(NOD* &cap, int valoare)
{
    NOD *a;
    NOD *c;
    c=cap;
    if(cap->val == valoare)
    {
        c = new NOD;
        cout<<"Valoarea de inserat: ";
        cin>>c->val;
        c->leg = cap;
        cap = c;
    }
    else
    {
        while(c->leg->val != valoare && c)
            c = c->leg;
        a = new NOD;
        cout<<"Valoarea de inserat: ";
        cin>>a->val;
        a->leg = c->leg;
        c->leg = a;
    }
}

void InserarePozitie(NOD* &cap, int poz)
{
    int i=1;
    NOD *a;
    NOD *c;
    c = cap;
    poz--;
    while(c!=NULL && i < poz)
    {
        c = c->leg;
        i++;
    }
    if(i==poz)
    {
        a = new NOD;
        cout<<"Valoarea de inserat: ";
        cin>>a->val;
        a->leg = c->leg;
        c->leg = a;
    }
    else cout<<"Pozitia inserata este prea mare!";
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
    cap = new NOD;
    cap = NULL;
    for(int i=1;i<=5;i++)
    InserareInceput(cap);
    InserarePozitie(cap,3);
    InserareDupa(cap,4);
    InserareInainte(cap,4);
    Afisare(cap);
    return 0;
}
