#include <iostream>
#include <climits>
#include <math.h>
#include <stdlib.h>

using namespace std;

struct punct
{
    int x,y;
};

void distanta(punct *a, punct *M, int p, int q)
{
    int i,z;
    for(i=0; i<q; i++)
    {
        int Min=INT_MAX;
        for(int j=0; j<p; j++)
        {
            z=abs(a[j].x-M[i].x) + abs(a[j].y-M[i].y);
            if(z<Min) Min = z;
        }
        cout<<"d(("<<M[i].x<<","<<M[i].y<<"),1)="<<Min<<endl;
    }

}

int main()
{
    int p,q;
    cin>>p>>q;
    punct a[100];
    punct M[100];
    for(int i=0; i<p; i++)
        cin>>a[i].x>>a[i].y;
    for(int i=0; i<q; i++)
        cin>>M[i].x>>M[i].y;
    distanta(a,M,p,q);
    return 0;
}
