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
    else if(x <= radacina->val)
        insert(radacina->st,x);
    else insert(radacina->dr,x);
}

void parcurgere_rsd(arbore* radacina, int x, int y)
{
    arbore* a=radacina;
    if(a!=NULL)
    {
        if(a->val >= x && a->val <= y)
            cout<<a->val<<" ";
        parcurgere_rsd(a->st);
        parcurgere_rsd(a->dr);
    }
}

int main()
{
    int k1,k2,x,n;
    arbore *radacina=NULL;
    cin>>k1>>k2>>n;
    for(int i=0;i<n;i++)
    {cin>>x;insert(radacina,x);}
    parcurgere_rsd(radacina,k1,k2);
    return 0;
}
