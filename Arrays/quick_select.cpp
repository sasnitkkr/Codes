#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
M-1: Sort return a[k-1] - nlogn
M-2: min PQ pop k-1 ele & return top - logn->push/pop nlogn + nlogk
M-3: max PQ klogk + (n-k)logk -> insert k in maxHeap and decrease top using n-k ele
M-4: quick select
*/

/* quick-select */

int partition(int a[], int l, int r)
{
    int p = r;
    int i = l-1;
    for(int j=l; j<r; j++)
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

int partition_r(int a[], int l, int r)
{
    srand(time(0));
    int random = l + rand() % (r-l+1);
    swap(a[random], a[r]);
    return partition(a, l, r);
}

int kth_smallest(int a[], int l, int r, int k)
{
    if(l<=r)
    {
        int pi = partition_r(a, l, r);
        if(pi == k-1)
            return a[pi];
        else if(pi > k-1)
            return kth_smallest(a, l, pi-1, k);
        else
            return kth_smallest(a, pi+1, r, k);
    }
}

void run_case() 
{
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<kth_smallest(a, 0, n-1, k)<<"\n";
    
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
