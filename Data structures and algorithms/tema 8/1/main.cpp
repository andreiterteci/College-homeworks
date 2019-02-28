#include <iostream>
#include <climits>

using namespace std;

int maxim_subsir_continuu(int *a, int n)
{
    int max_curent = INT_MIN, max_pana_aici = 0;
    for(int i=0; i<n; i++)
    {
        max_pana_aici = max_pana_aici + a[i];
        if(max_curent < max_pana_aici)
            max_curent = max_pana_aici;
        else
            if(max_pana_aici < 0)
            max_pana_aici = 0;
    }
    return max_curent;
}

int maxim_subsir_noncontinuu(int *a, int n)
{
    int max_curent = 0;
    for(int i=0; i<n; i++)
    {
        if(a[i] > 0)
            max_curent += a[i];
    }
    if(max_curent==0) max_curent = maxim(a,n);
    return max_curent;
}

int maxim(int *a, int n)
{
    int max=INT_MIN;
    for(int i=0;i<n;i++)
        if(a[i]>max) max = a[i];
    return max;
}

int main()
{
    int n;
    int *a;
    a= new int[n];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxim_subsir_noncontinuu(a,n);
    return 0;
}
