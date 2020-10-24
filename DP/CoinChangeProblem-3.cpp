#include<bits/stdc++.h>
using namespace std;
int count(int coins[], int n, int sum)
{
    int bottomUp[n+1][sum+1];
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i==0)
                bottomUp[i][j]=0;
            else if(j==0)
                bottomUp[i][j]=1;
            else
            {
                int res=bottomUp[i-1][j];
                if(coins[i-1]<=j)
                    res= res+bottomUp[i][j-coins[i-1]];
                bottomUp[i][j]=res;
            }
        }
    }
    return bottomUp[n][sum];
}
void solve()
{
    int n,sum;
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
