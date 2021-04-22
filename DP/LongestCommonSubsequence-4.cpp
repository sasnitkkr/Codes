#include <bits/stdc++.h>
using namespace std;

string LCS(string s1, string s2)
{
    int m = s1.length(), n = s2.length();
  
    int dp[m+1][n+1];
  
    for(int i=0; i<=m; i++)
        dp[i][0]=0;
  
    for(int i=1; i<=n; i++)
        dp[0][i]=0;
  
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
  
    string s;
  
    int i=m;
    int j=n;
  
    while(i>=1 && j>=1)
    {
        if(s1[i-1]==s2[j-1])
        {
            s.push_back(s1[i-1]);
            i=i-1;
            j=j-1;
        }
        else
        {
            if(dp[i-1][j]==dp[i][j])
            {
                i=i-1;
            }
            else
            {
                j=j-1;
            }
        }    
    }
  
    reverse(s.begin(),s.end());
  
    return s;
} 

void solve()                                                            
{                                                           
    string s1, s2;
    cin>>s1>>s2;
    cout<<LCS(s1,s2)<<"\n";                                                    
}                                                           
                                                           
int main()
{
                                                           
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
                                                           

    return 0; 
}
