#include <iostream>

using namespace std;

struct NOD
{
    int val;
    NOD *leg;
};

void InserareInceput(NOD* &cap, long x)
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
        cout<<cap->val<<" ";
        cap= cap->leg;
    }
}

int main()
{
    long a,b,x,c=0;
    cin>>a>>b;
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    x=a+b;
    while(x)
    {
        c=x%10;
        InserareInceput(cap,c);
        x=x/10;
    }
    Afisare(cap);
    return 0;
}
