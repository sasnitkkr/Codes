#include<bits/stdc++.h>
using namespace std;
int memo[100][100];
int LCS(string s1, string s2, int m, int n)
{
    if(memo[m][n]==-1)
    {
        if(m==0 || n==0)
            memo[m][n]=0;
        else
        {
            if(s1[m-1]==s2[n-1])
                memo[m][n]=1+LCS(s1,s2,m-1,n-1);
            else
                memo[m][n]=max(LCS(s1,s2,m,n-1),LCS(s1,s2,m-1,n));
        }
    }
    return memo[m][n];
}
void solve()
{
    string s1, s2;
    int m, n;
    cin>>s1>>s2;
    m=s1.length();
    n=s2.length();
    memset(memo, -1, sizeof(memo));
    cout<<LCS(s1,s2,m,n)<<"\n";
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
