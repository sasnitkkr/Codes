/*
Given two strings
Replace>Insert=Delete
so that s1 becomes s2
*/
#include<bits/stdc++.h>
using namespace std;
#define min(a,b,c) min(min(a,b),c)
int eD(string s1, string s2, int m, int n)
{
    if(m==0) return n;
    if(n==0) return m;
    if(s1[m-1]==s2[n-1])
        return eD(s1,s2,m-1,n-1);
    //try insert delete update
    return 1+min(eD(s1,s2,m,n-1), eD(s1,s2,m-1,n), eD(s1,s2,m-1,n-1));
}
void solve()
{
    int m, n;
    string s1, s2;
    cin>>s1>>s2;
    m=s1.length();
    n=s2.length();
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
