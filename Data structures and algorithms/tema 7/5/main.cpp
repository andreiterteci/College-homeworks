#include <iostream>

using namespace std;

int k;

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
    else if(x <= radacina->val)
        insert(radacina->st,x);
    else insert(radacina->dr,x);
}

void parcurgere_srd(arbore* radacina)
{
    arbore* a=radacina;
    if(a!=NULL)
    {
        parcurgere_srd(a->st);
        if(k==1)
        cout<<a->val<<" ";
        k--;
        parcurgere_srd(a->dr);
    }
}


int main()
{
    arbore* radacina=NULL;
    cin>>k;
    int x,n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {cin>>x;insert(radacina,x);}
    parcurgere_srd(radacina);
    return 0;
}
