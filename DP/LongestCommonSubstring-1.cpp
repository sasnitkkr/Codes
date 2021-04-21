/*
Source :- https://www.youtube.com/watch?v=NvmJBCn4eQI
Time :- O(m*n)
Space :- O(m*n)
Loginc :- 1. Find All Prefixes of s1  
          2. Find All Prefixes of s2
          3. Find Longest Common Suffix
*/
#include <bits/stdc++.h>
using namespace std;
                                                           
int LIS(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    int ans = 0;
    for(int i=0; i<=m; i++)
        dp[i][0]=0;
    for(int i=1; i<=n; i++) 
        dp[0][i]=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1; // diagonally up  + 1
            }
            else
            {
                dp[i][j] = 0; // if last char not same => can't be common suffix
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;   
}  

int main()
{
                                                           
    int t=1;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;
        cout<<LIS(s1,s2)<<"\n";
    }
                                                           

    return 0; 
}
/*
4
pqabcxy
xyzabcp
abcdxyz
xyzabcd
GeeksforGeeks
GeeksQuiz
zxabcdezy
yzabcdezx

Exp OP :- 3, 4, 5, 6
*/
