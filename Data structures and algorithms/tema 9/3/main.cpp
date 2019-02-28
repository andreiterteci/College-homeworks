#include <iostream>

using namespace std;

void citire(int v[100][100], int &n, int &m)
{
    int x,y;
    cin>>n>>m;
    for(int i=1;i<m;i++)
    {cin>>x>>y;v[x][y]=1;}
}

void drum(int *v, int n)
{
    int i, j, k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if((v[i][j]==0) && (i!=k) && (j!=k))
                    v[i][j]=v[i][k]*v[k][j];
    cout<<endl;
}

void afisare(int *v, int n)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int v[100][100],n,m,x,y,ok=0;
    citire(v,n,m);
    drum(v,n);
    for(int i=0; i<n; i++)
        if(v[i][i]==1)
        {
            ok=1;
            cout<<i<<" ";
        }
    if(ok==0)
        cout<<"REALIZABIL";
    return 0;
}
