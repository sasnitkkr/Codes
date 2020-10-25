/*
Binary Search to find ceil
tail[i] stores the minimum possible tail value for LIS of length (i+1)
length of tail is required answer
*/
#include<bits/stdc++.h>
using namespace std;
int ceilIndex(vector<int> tail, int l, int r, int x)
{
    while(l<r)
    {
        int m=l+(r-l)/2;
        if(tail[m]>=x)
            r=m;
        else
            l=m+1;
    }
    return r;
}
int LIS(int a[], int n)
{
    vector<int> tail;
    tail.push_back(a[0]);
    for(int i=1; i<n; i++)
    {
        if(a[i]>tail[tail.size()-1])
            tail.push_back(a[i]);
        else
        {
            tail[ceilIndex(tail,0,i-1,a[i])]=a[i];
        }
    }
    return tail.size();
}
void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<LIS(a,n)<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*
Test Cases
6
4
3 10 2 8
7
3 4 2 8 10 5 1
5
3 4 2 8 10
8
4 10 6 5 8 11 2 20
3
10 20 30
3
30 20 10*/
