#include <iostream>

using namespace std;

struct NOD
{
    int val;
    NOD *leg;
};

void InserareSfarsit(NOD* &cap)
{
    NOD* elem = new NOD;
    elem->leg = NULL;
    cin>>elem->val;
    if(cap == NULL)
        cap= elem;
    else
    {
        NOD *r = cap;
        while(r->leg != NULL)
            r = r->leg;
        r->leg = elem;
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
    int n;
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    cout<<"Dati numarul de elemente pe care doriti sa le inserati la sfarsitul listei: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    InserareSfarsit(cap);
    Afisare(cap);
    return 0;
}
