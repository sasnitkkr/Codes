#include<bits/stdc++.h>
using namespace std;
#define min(a,b,c) min(min(a,b),c)
int eD(string s1, string s2, int m, int n)
{
    int bottomUp[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i==0 || j==0)
            {
                if(i==0) bottomUp[i][j]=j;
                if(j==0) bottomUp[i][j]=i;
            }
            else if(s1[i-1]==s2[j-1])
                bottomUp[i][j]=bottomUp[i-1][j-1];
            else
            {
                //try insert update delete
                bottomUp[i][j]=1+min(bottomUp[i][j-1],bottomUp[i-1][j-1],bottomUp[i-1][j]);            
            }
        }
    }
    return bottomUp[m][n];
}
void solve()
{
    string s1, s2;
    cin>>s1>>s2;
    int m=s1.length(), n=s2.length();
    cout<<eD(s1,s2,m,n)<<"\n";
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
