/*
Given n, a, b, c
Find maximum possible cuts of n where each cut is either a, b, c
Time Complexity:=O(3^n)
*/
#include<bits/stdc++.h>
using namespace std;
#define max(a,b,c) max(max(a,b),c)
int maxCuts(int n, int a, int b, int c)
{
    if(n<0)
        return -1;
    if(n==0)
        return 0;
    int res=max(maxCuts(n-a,a,b,c), maxCuts(n-b,a,b,c), maxCuts(n-c,a,b,c));
    if(res==-1)
        return res;
    else 
        return res+1;
}
void solve()
{
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    cout<<maxCuts(n,a,b,c)<<"\n";
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
