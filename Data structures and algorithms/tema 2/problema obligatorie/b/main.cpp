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
    int n;
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    cout<<"Dati numarul de elemente pe care doriti sa le inserati la inceputul listei: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    InserareInceput(cap);
    Afisare(cap);
    return 0;
}
