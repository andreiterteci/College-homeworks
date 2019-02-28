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

NOD* CautarePozitie(NOD *cap, int poz)
{
    int i=1;
    NOD *c;
    c=cap;
    while(c != NULL && i<poz)
        {
            c = c->leg;
            i++;
        }
   if(i==poz) return c;
   else return NULL;
}

int main()
{
    int n;
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    for(int i=1; i<=5; i++)
    InserareSfarsit(cap);
    CautarePozitie(cap,5);
    return 0;
}
