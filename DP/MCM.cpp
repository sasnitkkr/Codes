#include <bits/stdc++.h>
using namespace std;

/*
    MCM[i,j]
    Multiply Matrices [Ai to Aj]
    rerurn minimum scalar multiplication

    c[i,j] = min   { c[i,k] + c[k+1,j] + d[i-1]*d[k]*d[j] }
            i<=k<j 

     i<=k<j => fill diagonally -> right part of matrix
*/

/* Tabulation */

int MCM(vector<int> &a, int i, int j)
{
    int dp[j+1][j+1]; // return i=1 to j dp[i][j]
    for(int k=1; k<=j; k++)
    {
        dp[k][k]=0;
    }
    for(int l=j-1; l>=1; l--)
    {
        // decide 2 var to run each time
        for(int u=1; u<=l; u++)
        {
            int v=u+(j-l);
            dp[u][v]=INT_MAX;
            for(int k=u; k<v; k++)
            {
                dp[u][v] = min(dp[u][v], dp[u][k]+dp[k+1][v]+a[u-1]*a[k]*a[v]);
            }
        }
    }
    return dp[i][j];
}

/* MEMOIZATION */

int dp[1001][1001];

int MCM(vector<int> &a, int i, int j)
{
    if(dp[i][j]==-1)
    {
        int ans;
        if(i==j)
        {
            ans = 0;
        }
        else
        {
            ans = INT_MAX;
            for(int k=i; k<j; k++)
            {
                int t = MCM(a,i,k)+MCM(a,k+1,j)+a[i-1]*a[k]*a[j];
                ans = min(ans,t);
            }
        }
        dp[i][j] = ans;
    }
    return dp[i][j];
}


/* RECURSIVE CODE */ 

int MCM(vector<int> &a, int i, int j)                                                            
{   
    if(i==j) return 0;

    int ans = INT_MAX;                                   
    for(int k=i; k<j; k++)
    {
        int t = MCM(a,i,k)+MCM(a,k+1,j) + a[i-1]*a[k]*a[j];
        ans = min(ans,t);
    }
    return ans;                                                      
} 
                                                        
                                                           
int main()
{
                                                           
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        //memset(dp,-1,sizeof(dp));
        cout<<MCM(a,1,n-1)<<"\n";
    }
                                                           

    return 0; 
}
