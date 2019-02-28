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

void stergere_inceput(nod* &prim)
{
    if(prim==NULL) return;

    nod* a = prim;
    prim=prim->next;
    prim->last=NULL;
    delete a;
}

void stergere_sfarsit(nod* &prim)
{
    if(prim==NULL) return;
    nod* a=prim;
    while(a->next!=NULL)
        a=a->next;
    a->last->next=NULL;
    delete a;
}

int main()
{
    nod *prim;
    prim = new nod;
    prim = NULL;
    int i;
    cout<<"1.Adaugare inceput"<<endl;
    cout<<"2.Adaugare sfarsit"<<endl;
    cout<<"3.Stergere inceput"<<endl;
    cout<<"4.Stergere sfarsit"<<endl;
    cout<<"0.Iesire"<<endl;
    cin>>i;
    while(i!=0)
    {
        switch(i)
        {
        case 1:
            adaugare_inceput(prim);
            break;
        case 2:
            adaugare_sfarsit(prim);
            break;
        case 3:
            stergere_inceput(prim);
            break;
        case 4:
            stergere_sfarsit(prim);
        cout<<"1.Adaugare inceput"<<endl;
        cout<<"2.Adaugare sfarsit"<<endl;
        cout<<"3.Stergere inceput"<<endl;
        cout<<"4.Stergere sfarsit"<<endl;
        cout<<"0.Iesire"<<endl;
        cin<<i;
    }
    return 0;
}
      break;
        }
        cout<<endl;
        cout<<"1.Adaugare inceput"<<endl;
        cout<<"2.Adaugare sfarsit"<<endl;
        cout<<"3.Stergere inceput"<<endl;
        cout<<"4.Stergere sfarsit"<<endl;
        cout<<"0.Iesire"<<endl;
        cin<<i;
    }
    return 0;
}
