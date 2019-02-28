#include <iostream>

using namespace std;

struct NOD
{
    int val;
    NOD *leg;
};


void InserareSfarsit(NOD* &cap, int x)
{
    NOD* elem = new NOD;
    elem->leg = NULL;
    elem->val=x;
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
    elem->val = x;
    elem->leg = cap;
    cap = elem;
}

void Afisare(NOD* cap)
{
    while(cap!=NULL)
    {
        cout<<cap->val;
        cap= cap->leg;
    }
}

int main()
{
    long a,b,x,y,c=0,r=0;
    long q,p;
    cin>>a>>b;
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    y=a;
    x=b%10;
    q=1;
    while(x)
    {
        p=0;
        while(y)
        {r=(y%10*x)+c;
        c=r/10;
        //InserareInceput(cap,r%10);
        y/=10;
        p=p*10 + r;
        }
        q=q+p;
        q*=10;
        y=a;
        b/=10;
        x=b%10;
    }
    while(q)
    {
        InserareSfarsit(cap,q%10);
        q/=10;
    }
    Afisare(cap);
    return 0;
}
