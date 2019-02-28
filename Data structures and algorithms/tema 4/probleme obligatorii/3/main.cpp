#include <iostream>

using namespace std;

struct NOD
{
    int val;
    NOD *leg;
};

void InserareInceput(NOD* &cap, int x)
{
    NOD* elem = new NOD;
    elem->val=x;
    elem->leg = cap;
    cap = elem;
}

int main()
{
    int n, max1=0, max2=0,nr=0, x, y;
    int *v;
    NOD *a;
    a = new NOD;
    a = NULL;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        InserareInceput(a,x);
        nr++;
        if(x>max1) max1 = x;
    }
    v = new int[max1+1];
    for(int i=0; i<=max1; i++)
        v[i]=0;
    while(a!=NULL)
    {
        v[a->val]++;
        a=a->leg;
    }
    for(int i=0; i<=max1; i++)
        if(v[i]>max2)
        {
            max2=v[i];
            y=i;
        }
    if(max2 >= nr/2+1) cout<<y;
    else cout<<"Nu exista element majoritar";

    return 0;
}
