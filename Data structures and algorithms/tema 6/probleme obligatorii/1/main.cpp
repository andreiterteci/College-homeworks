#include <iostream>

using namespace std;

struct nod
{
    int val;
    nod *next, *last;
};

void adaugare_inceput(nod* &prim)
{
    nod *a;
    a=new nod;
    cin>>a->val;
    a->next=prim;
    a->last=NULL;
    if(prim!=NULL) prim->last=a;
    prim=a;
}

void adaugare_sfarsit(nod* &prim)
{
    nod *a;
    a=new nod;
    cin>>a->val;
    a->next=NULL;
    a->last=NULL;
    if(prim==NULL) prim=a;
    else
    {
        nod *b=prim;
        while(b->next!=NULL)
            b=b->next;
        b->next=a;
        a->last=b;
    }
}

void adaugare_interior(nod* &prim)
{
    nod *a=new nod;
    a->next=NULL;
    a->last=NULL;
    int k;
    cout<<"Introduceti valorea dupa care sa se adauge noua valoare: ";
    cin>>k; //valoarea dupa care sa se insereze elementul
    cout<<"Introduceti valoarea ce trebuie adaugata: ";
    cin>>a->val;
    nod *b=new nod;
    b=prim;
    while(b->val != k)
        b=b->next;
    a->last=b->last;
    a->next=b;
    b->last=a;
}

void stergere_pozitie(nod* &prim)
{
    if(prim==NULL) return;
    int poz,i=0;
    cout<<"Dati pozitia de pe care sa fie sters elementul"<<endl;
    cin>>poz;
    if(poz==0)
    {
        nod* a = prim;
        prim=prim->next;
        prim->last=NULL;
        delete a;
        return;
    }
    nod *a;
    a=prim;
    while(a!=NULL && i<poz)
    {
        a=a->next;
        i++;
    }
    if(i==poz)
    {
        a->last->next=a->next;
        a->next->last=a->last;
        delete a;
    }
    else return;
}

void stergere_valoare(nod* &prim)
{
    int valoare;
    cout<<"Dati valoarea"<<endl;
    cin>>valoare;
    if(prim==NULL) return;
    if(prim->val==valoare)
    {
        nod* a=prim;
        prim=prim->next;
        prim->last=NULL;
        delete a;
        return;
    }
    nod *a=prim;
    while(a!=NULL && a->val != valoare)
        a=a->next;
    if(a!=NULL)
    {
        a->last->next=a->next;
        a->next->last=a->last;
        delete a;
    }
}

void afisare_crescatoare(nod* prim)
{
    while(prim)
    {
        cout<<prim->val<<" ";
        prim=prim->next;
    }
}

void afisare_inversa(nod* prim)
{
    nod *a = new nod;
    a=prim;
    while(a->next)
        a=a->next;
    while(a)
    {
        cout<<a->val<<" ";
        a=a->last;
    }
}
int main()
{
    int n,i,k;
    nod *prim;
    prim = new nod;
    prim = NULL;
    cout<<"1.Adaugarea unui element la inceput"<<endl;
    cout<<"2.Adaugarea unui element la sfarsit"<<endl;
    cout<<"3.Adaugarea unui element in interiorul listei"<<endl;
    cout<<"4.Afisarea elementelor listei in ordinea introducerii lor"<<endl;
    cout<<"5.Afisarea elementelor listei in ordine inversa"<<endl;
    cout<<"6.Stergerea unui element din lista stiind numarul lui de ordine"<<endl;
    cout<<"7.Stergerea unui element din lista stiind valoarea lui"<<endl;
    cout<<"0.Iesire"<<endl;
    cin>>i;
    while(i!=0)
    {

        switch(i)
        {
        case 1:
        {
            cout<<"Dati numarul de elemente pe care doriti sa le adaugati la inceputul listei"<<endl;
            cin>>n;
            cout<<"Introduceti valorile: "<<endl;
            for(int j=0; j<n; j++)
                adaugare_inceput(prim);
        }
        break;
        case 2:
        {
            cout<<"Dati numarul de elemente pe care doriti sa le adaugati la inceputul listei"<<endl;
            cin>>n;
            cout<<"Introduceti valorile: "<<endl;
            for(int j=0; j<n; j++)
                adaugare_sfarsit(prim);
        }
        break;
        case 3:
            adaugare_interior(prim);
            break;
        case 4:
            afisare_crescatoare(prim);
            break;
        case 5:
            afisare_inversa(prim);
            break;
        case 6:
            stergere_pozitie(prim);
            break;
        case 7:
            stergere_valoare(prim);
            break;
        }
        cout<<endl;
        cout<<"1.Adaugarea unui element la inceput"<<endl;
        cout<<"2.Adaugarea unui element la sfarsit"<<endl;
        cout<<"3.Adaugarea unui element in interiorul listei"<<endl;
        cout<<"4.Afisarea elementelor listei in ordinea introducerii lor"<<endl;
        cout<<"5.Afisarea elementelor listei in ordine inversa"<<endl;
        cout<<"6.Stergerea unui element din lista stiind numarul lui de ordine"<<endl;
        cout<<"7.Stergerea unui element din lista stiind valoarea lui"<<endl;
        cout<<"0.Iesire"<<endl;
        cin>>i;
    }
    return 0;
}
