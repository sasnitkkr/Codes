#include<bits/stdc++.h>
using namespace std;
#define min(a,b,c) min(min(a,b),c)
int memo[100][100];
int eD(string s1, string s2, int m, int n)
{
    if(memo[m][n]==-1)
    {
        int res;
        if(m==0||n==0)
        {
            if(m==0) res=n;
            if(n==0) res=m;   
        }
        else
        {
            if(s1[m-1]==s2[n-1])
                res=eD(s1,s2,m-1,n-1);
            else //try insert delete update
                res=1+min(eD(s1,s2,m,n-1), eD(s1,s2,m-1,n), eD(s1,s2,m-1,n-1));
        }
        memo[m][n]=res;
    }
    return memo[m][n];
}
void solve()
{
    memset(memo,-1,sizeof(memo));
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
