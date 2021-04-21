/*
Time -> NlogN
Space -> O(N)
Source -> GFG DSA
*/
#include<bits/stdc++.h>
using namespace std;

int LIS(int a[], int n)
{
    vector<int> dp;
    for(int i=0; i<n; i++)
    {
        if(dp.size()==0 || dp.back()<a[i])
        {
            dp.push_back(a[i]);
        }
        else
        {
            auto itr = lower_bound(dp.begin(), dp.end(),a[i]); // Binary Search -> Log(N)
            *itr = a[i];
        }
    }
    return dp.size();
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        cout<<LIS(a,n)<<"\n";
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
30 20 10
*/
