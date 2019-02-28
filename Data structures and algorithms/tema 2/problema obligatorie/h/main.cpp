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

void StergereElement(NOD* a)
{
 NOD* b = a->leg;
 a->leg = a->leg->leg;
delete b;
}
void StergerePozitie(NOD* &cap, int pozitie)
{
if (cap == NULL)
 return;
if (pozitie == 1)
 {
 NOD* a = cap;
 cap = cap->leg;
 delete a;
 return;
 }
NOD* b = CautarePozitie(cap, pozitie-1);
StergereElement(b);
}

int main()
{
    int n;
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    for(int i=1; i<=5; i++)
    InserareSfarsit(cap);
    StergerePozitie(cap,1);
    Afisare(cap);
    return 0;
}
