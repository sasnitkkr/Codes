/*
Order of rows and column matters
row-sum
column-no of coins
given sum different coins
*/
#include<bits/stdc++.h>
using namespace std;
int count(int coins[], int n, int sum)
{
    int bottomUp[sum+1][n+1];
    //i-sum
    //j-no of coins
    for(int i=0; i<=sum; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0)
                bottomUp[i][j]=1;
            else if(j==0)
                bottomUp[i][j]=0;
            else
            {
                bottomUp[i][j]=bottomUp[i][j-1];
                if(coins[j-1]<=i)
                    bottomUp[i][j]+=bottomUp[i-coins[j-1]][j];
            }
        }
    }
    return bottomUp[sum][n];
    
}
void solve()
{
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
