#include<bits/stdc++.h>
using namespace std;
int memo[100][100];
int count(int coins[], int n, int sum)
{
    if(memo[n][sum]==-1)
    {
        int res;
        if(sum==0)
            res=1;
        else if(n==0)
            res=0;
        else
        {
            res=count(coins,n-1,sum);
            if(coins[n-1]<=sum)
                res=res+count(coins,n,sum-coins[n-1]);   
        }
        memo[n][sum]=res;
    }
    return memo[n][sum];
}
void solve()
{
    memset(memo,-1,sizeof(memo));
    int n, sum;
    cin>>n;
    int coins[n];
    for(int i=0; i<n; i++)
        cin>>coins[i];
    cin>>sum;
    cout<<count(coins,n,sum)<<"\n";
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
