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

void StergereElement(NOD* a)
{
 NOD* b = a->leg;
 a->leg = a->leg->leg;
delete b;
}
void StergereValoare(NOD* &cap, int valoare)
{
    NOD *a;
    NOD *c;
    if(c == NULL) //lista vida
        return;
    if(cap->val == valoare) //primul element
       {
           a = cap;
           cap = cap->leg;
           delete a;
           return;
       }
    c = cap;
        while(c->leg != NULL && c->leg->val !=valoare)
            c=c->leg;
        if(c->leg != NULL)
            StergereElement(c);
}

int main()
{
    int n;
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    for(int i=1; i<=5; i++)
    InserareSfarsit(cap);
    StergereValoare(cap,3);
    Afisare(cap);
    return 0;
}
