/*
wt[] = {1, 3, 4, 5};
val[] = {1, 4, 5, 7};
W = 7;
o/p: Max Value That Can be stored in Bag of W=7 : 9

if item within capacity of W 2 Choice for each item either take or do not
else single choice of not taking it

Space -> O(Wxn)
Time -> O(Wxn) // just fill the table
*/
#include <bits/stdc++.h>
using namespace std;

//return max val that can be stored in Knapsack                                                          
int knapsack_BU(int wt[], int val[], int W, int n) 
{
    int dp[n+1][W+1];
    for(int i=0; i<W+1; i++)
        dp[0][i] = 0;
    for(int i=0; i<n+1; i++)
        dp[i][0] = 0;
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<W+1; j++)
        {
            if(wt[i-1]<=j)
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]); // take or do not take
            else
                dp[i][j] = dp[i-1][j]; // do not take if do not fit
        }
    }
    return dp[n][W];
}                                                           

//return max val that can be stored in Knapsack
int dp[100][100];

int knapsack_TD(int wt[], int val[], int W, int n) 
{
    if(dp[n][W]==-1)
    {
        int ans;
        if(W == 0 || n==0) ans = 0;
        if(wt[n-1]<=W)
        {
            ans = max(val[n-1]+knapsack_TD(wt,val,W-wt[n-1],n-1), knapsack_TD(wt,val,W,n-1));
        }
        else
        {
            ans = knapsack_TD(wt, val, W, n-1); 
        }
        dp[n][W] = ans;
    }
    return dp[n][W];
}                                                  
                                                           
int main()
{                                                      
    int t;                                                 
    cin>>t;                                                
    while(t--)                                             
    {        
        int W, n;
        cin>>n>>W;                                             
        int wt[n], val[n];
        for(int i=0; i<n; i++)
        {
            cin>>wt[i];
        }              
        for(int i=0; i<n; i++)
        {
            cin>>val[i];
        }   
        memset(dp,-1,sizeof(dp));  // uncomment if using TD                                  
        cout<<knapsack_TD(wt,val,W,n)<<"\n";                                                  
    }                                                      
 return 0;
}
