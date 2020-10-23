#include<bits/stdc++.h>
using namespace std;
int LCS(string s1, string s2)
{
    int m, n;
    m=s1.length();
    n=s2.length();
    int bottomUp[m+1][n+1];
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
        {
            if(i==0 || j==0)
            {
                bottomUp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                bottomUp[i][j]=1+bottomUp[i-1][j-1];   
            }
            else
            {
                bottomUp[i][j]=max(bottomUp[i-1][j], bottomUp[i][j-1]);
            }
        }
    }
    return bottomUp[m][n];
}
void solve()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<LCS(s1,s2)<<"\n";
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
