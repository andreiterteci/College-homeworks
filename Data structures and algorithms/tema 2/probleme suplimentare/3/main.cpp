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

void InserarePozitie(NOD* &cap, int poz, float x)
{
    int i=1;
    NOD *a;
    NOD *c;
    c = cap;
    poz--;
    while(c!=NULL && i < poz)
    {
        c = c->leg;
        i++;
    }
    if(i==poz)
    {
        a = new NOD;
        a->val=x;
        a->leg = c->leg;
        c->leg = a;
    }
}

void medie(NOD* &cap)
{
    NOD *a;
    a=cap;
    int poz=1;
    int s=0;
    int nr=0;
    while(a!=NULL)
    {

        s+=a->val;
        a=a->leg;
         poz++;
        nr++;
        if(nr==2)
        {
            InserarePozitie(cap,poz,s*1./2);
            s=0;
            nr=0;
        }

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

using namespace std;

int main()
{
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    for(int i=1;i<=5;i++)
    InserareSfarsit(cap);
    medie(cap);
    Afisare(cap);

    return 0;
}
