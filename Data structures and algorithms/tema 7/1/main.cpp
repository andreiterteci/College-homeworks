#include <iostream>

using namespace std;

struct arbore
{
    int val;
    arbore *st,*dr;
};

void insert(arbore* &radacina, int x)
{
    if(radacina==NULL)
    {
        radacina = new arbore;
        radacina->val=x;
        radacina->st = radacina->dr=NULL;
    }
    else if(radacina->st==NULL)
        insert(radacina->st,x);
    else if(radacina->dr==NULL)
        insert(radacina->dr,x);
}
void parcurgere_rsd(arbore* radacina)
{
    arbore* a=radacina;
    if(a!=NULL)
    {
        cout<<a->val<<" ";
        parcurgere_rsd(a->st);
        parcurgere_rsd(a->dr);
    }
}

void parcurgere_srd(arbore* radacina)
{
    arbore* a=radacina;
    if(a!=NULL)
    {
        parcurgere_srd(a->st);
        cout<<a->val<<" ";
        parcurgere_srd(a->dr);
    }
}

void parcurgere_sdr(arbore* radacina)
{
    arbore* a=radacina;
    if(a!=NULL)
    {
        parcurgere_sdr(a->st);
        parcurgere_sdr(a->dr);
        cout<<a->val<<" ";
    }
}

int main()
{
    arbore *radacina;
    radacina = NULL;
    for(int i=0; i<5; i++)
        insert(radacina,i);
    cout<<endl;
    parcurgere_srd(radacina);
    cout<<endl;
    parcurgere_rsd(radacina);
    cout<<endl;
    parcurgere_sdr(radacina);
    return 0;
}
