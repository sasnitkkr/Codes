/*
coins:-{1,2,3}, Sum:-4
Possible Ways:- {(1,1,1,1),(1,3),(1,1,2),(2,2)}
Ans=4
*/
#include<bits/stdc++.h>
using namespace std;
int count(int coins[], int n, int sum)
{
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    int res=count(coins, n-1, sum);
    if(coins[n-1]<=sum)
        res=res+count(coins, n, sum-coins[n-1]);
    return res;
}
void solve()
{
    int n, sum;
    cin>>n;
    int coins[n];
    for(int i=0; i<n; i++)
        cin>>coins[i];
    cin>>sum;
    cout<<count(coins, n, sum)<<"\n";
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
