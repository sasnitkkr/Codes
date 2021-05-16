/*
Time Complexity :- 
 Worst Case :- O(n^2) // pi is always greatest/smallest
 Avg. Case :- O(nlogn) // Array Evenly divided
*/

#include<bits/stdc++.h>
using namespace std;


/* CLRS Algo Ascending */
int parition(int a[], int l, int r)
{
    int p = r;
    int i = l-1;
    for(int j = l; j<r; j++)
    {
        if(a[j]<a[p])
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[p]);
    return i+1;
}

int quick_sort(int a[], int l, int r)
{
    if(l<r)
    {
        int pi = parition(a, l, r);
        quick_sort(a, l, pi-1);
        quick_sort(a, pi+1, r);
    }
}

void run_case() 
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    quick_sort(a, 0, n-1);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        run_case();
    }
    return 0;
}
