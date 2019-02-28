#include <iostream>
using namespace std;

void heap(int v[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    int aux;

    if (left < n && v[left] > v[largest])
        largest = left;

    if (right < n && v[right] > v[largest])
        largest = right;

    if (largest != i)
    {
        aux = v[i];
        v[i] = v[largest];
        v[largest] = aux;
        heap(v, n, largest);
    }
}

void heapSort(int v[], int n)
{
    int aux;

    for (int i = n / 2 - 1; i >= 0; i--)
        heap(v, n, i);

    for (int i=n-1; i>=0; i--)
    {
        // Mut radacina la sfarsit
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        heap(v, i, 0);
    }
}

void print(int v[], int n)
{
    for (int i=0; i<n; ++i)
        cout << v[i] << " ";
    cout << "\n";
}

int main()
{
    int v[100];
    int n;

    cin>>n;

    for(int i = 0; i < n; i++)
        cin>>v[i];

    heapSort(v, n);

    print(v, n);
}
