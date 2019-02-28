#include <iostream>

using namespace std;

struct nod
{
    int val,prioritate;
    nod *next, *last;
};

void adaugare(nod* &prim,int x, int k)
{
    nod *a=new nod;
    a->next=NULL;
    a->last=NULL;
    a->val=x;
    a->prioritate=k;
    nod *b=new nod;
    b=prim;
    while(b->prioritate <= k)
        b=b->next;
    a->last=b->last;
    a->next=b;
    b->last=a;
}

int verificare(nod* prim,int k)
{
    nod *a = prim;
    while(a!=NULL)
    {
        if(a->prioritate==k) return 1;
        a=a->next;
    }
    return 0;
}

void stergere_inceput(nod* &prim)
{
    if(prim==NULL) return;

    nod* a = prim;
    prim=prim->next;
    prim->last=NULL;
    delete a;
}

void afisare_crescatoare(nod* prim)
{
    while(prim)
    {
        cout<<prim->val<<" ";
        prim=prim->next;
    }
}

int main()
{
    int n,i,k,x;
    nod *prim;
    prim = new nod;
    prim = NULL;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>k>>x;
        if(verificare(prim,k)==1) adaugare(prim,k,x);
        else adaugare(prim,k+1,x);
    }
    afisare_crescatoare(prim);
    return 0;
}
