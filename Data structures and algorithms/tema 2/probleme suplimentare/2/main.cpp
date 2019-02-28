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

int Numarare(NOD* cap)
{
    NOD *a;
    int nr=0;
    a=cap;
    while(a!=NULL)
        {
            if(a->val%2==0) nr++;
            a = a->leg;
        }
    return nr;
}

float Media(NOD* cap)
{
    NOD* a;
    a=cap;
    int s=0;
    int nr=0;
    while(a!=NULL)
        {
            if(a->val%2!=0) {nr++;
                            s+=a->val;}
            a = a->leg;

        }
    return s*1./nr;

}

int main()
{
    int n;
    NOD *cap;
    cap = new NOD;
    cap = NULL;
    cout<<"Dati numarul de elemente din lista: ";
    cin>>n;
    cout<<endl;
    cout<<"Dati elementele: ";
    cout<<endl;
    for(int i=1;i<=n;i++)
        InserareSfarsit(cap);
    cout<<"Numarul elementelor pare este: "<<Numarare(cap);
    cout<<endl;
    cout<<"Media artimetica a elementelor impare este: "<<Media(cap);
    cout<<endl;

    return 0;
}
