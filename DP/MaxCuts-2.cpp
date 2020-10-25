#include<bits/stdc++.h>
using namespace std;
#define max(a,b,c) max(max(a,b),c)
int memo[100];
int maxCuts(int n, int a, int b, int c)
{
    if(n<0) return -1;
    else if(memo[n]==-1)
    {
        if(n==0)
            memo[n]=0;
        else 
        {
            int r=max(maxCuts(n-a,a,b,c),maxCuts(n-b,a,b,c),maxCuts(n-c,a,b,c));
            if(r<0)
                memo[n]=-1;
            else
                memo[n]=r+1;
        }
    }
    return memo[n];
}
void solve()
{
    memset(memo,-1,sizeof(memo));
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
/*
Test Cases
3
5 1 2 3
23 12 11 13
3 2 4 2
*/
