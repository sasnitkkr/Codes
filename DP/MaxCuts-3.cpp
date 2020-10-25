#include<bits/stdc++.h>
using namespace std;
int maxCuts(int n, int a, int b, int c)
{
    //dp[i] stores maxCuts for length i 
    int dp[n+1];
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        dp[i]=-1;
        if(i-a>=0) dp[i]=max(dp[i],dp[i-a]);
        if(i-b>=0) dp[i]=max(dp[i],dp[i-b]);
        if(i-c>=0) dp[i]=max(dp[i],dp[i-c]);
        if(dp[i]!=-1)
            dp[i]++;
    }
    return dp[n];
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
