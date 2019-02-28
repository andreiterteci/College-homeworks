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
        cap = elem;
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

void Inserare(NOD *a, NOD *b, NOD* &c, int n, int m)
{
    NOD *d,*e;
    d=new NOD;
    d=NULL;
    e=new NOD;
    e=NULL;
    int x=0, y=0;

    while(x<=n/2)
    {
        InserareSfarsit(d,a->val);
        a=a->leg;
        x++;
    }

    while(y<=m/2)
    {
        InserareSfarsit(e,b->val);
        b=b->leg;
        y++;
    }

    while(d!=NULL && e!=NULL)
    {
        if(d->val < e->val)
        {
            InserareSfarsit(c,d->val);
            d=d->leg;
        }
        else
        {
            InserareSfarsit(c,e->val);
            e=e->leg;
        }
    }

    if(d==NULL)
        while(e!=NULL)
        {
            InserareSfarsit(c,e->val);
            e=e->leg;
        }
    else if(e==NULL) while(d!=NULL)
        {
            InserareSfarsit(c,d->val);
            d=d->leg;
        }
}

int main()
{
    int n,m,x;
    NOD *a, *b, *c;
    a = new NOD;
    a = NULL;
    b = new NOD;
    b = NULL;
    c = new NOD;
    c = NULL;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        InserareSfarsit(a,x);
    }
    for(int i=1; i<=m; i++)
    {
        cin>>x;
        InserareSfarsit(b,x);
    }
    Inserare(a,b,c,n,m);
    Afisare(c);
    return 0;
}
