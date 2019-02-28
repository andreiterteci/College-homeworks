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

void inorder(arbore* radacina)
{
    if(radacina==NULL) return;
    inorder(radacina->st);
    cout<<radacina->val<<" ";
    inorder(radacina->dr);
}

int main()
{
    int i,x,n;
    arbore *radacina;
    radacina=NULL;
    cout<<"Dati nr de elem din sir: ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        insert(radacina,x);
    }
    inorder(radacina);

    return 0;
}
