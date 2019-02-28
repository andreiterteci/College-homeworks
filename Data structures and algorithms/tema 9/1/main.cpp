#include <iostream>

using namespace std;

int partitie(int *v,int s, int d)
{
    int aux,pivot,i;
    pivot = v[d];
    i = s-1;
    for(int j=s; j<=d-1; j++)
        if(v[j]<pivot)
        {
            i++;
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
        }
    aux=v[i+1];
    v[i+1]=v[d];
    v[d]=aux;
    return (i+1);
}

void quicksort(int *v, int s, int d)
{
    int p;
    if(s<d)
    {
        p = partitie(v,s,d);
        quicksort(v,s,p-1);
        quicksort(v,p+1,d);
    }
}

int greedy(int *Min, int n, int m)
{
    int cd=1;
    int durata=m;
    for(int i=0; i<n; i++)
    {
        if(durata>Min[i])
            durata-=Min[i];
        else
        {
            durata = m;
            durata-=Min[i];
            cd++;
        }
    }
    return cd;
}

int main()
{
    int *Min;
    int n,m;
    cout<<"Introduceti numarul de melodii: ";
    cin>>n;
    cout<<"Introduceti numarul maxim de minute al unui cd: ";
    cin>>m;
    Min=new int[n];
    cout<<"Introduceti durta fiecarei melodii: ";
    for(int i=0; i<n; i++)
        cin>>Min[i];
    quicksort(Min,0,n-1);
    cout<<greedy(Min,n,m);
    return 0;
}
