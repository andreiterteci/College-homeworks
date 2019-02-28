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

void InserareInceput(NOD* &cap, int x)
{
    NOD* elem = new NOD;
    elem->val=x;
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

void Var2(NOD* &a,int n)
{
    int x=0;
    NOD *q,*p;
    q=a->leg;
    p=a->leg->leg;
    a->leg=NULL;
    q->leg=a;
    a=q;
    x++;
    q=p;
    p=p->leg;
    while(x<=n/2)
    {
        q->leg=a;
        a=q;
        x++;
        q=p;
        p=p->leg;
    }
    q->leg=a;
    a=q;
}

int main()
{
    int n,x=1;
    NOD *cap, *a;
    cap = new NOD;
    cap = NULL;
    a = new NOD;
    a = NULL;
    cin>>n;
    for(int i=1; i<=n; i++)
        InserareSfarsit(cap);
//    1a
//    while(cap)
//    {
//        InserareInceput(a, cap->val);
//        cap=cap->leg;
//    }
    Var2(cap);
    Afisare(cap);
    return 0;
}
