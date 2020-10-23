/*LCS
Subsequence of BAZ
{"",B,A,Z,BA,BZ,AZ,BAZ}- 2^n
Time Complexity:- O(2^n)
*/
#include<iostream>
using namespace std;
int LCS(string s1, string s2, int m, int n)
{
    if(m==0 || n==0)
        return 0;
    else if(s1[m-1]==s2[n-1])
        return 1+LCS(s1,s2,m-1,n-1);
    else 
        return max(LCS(s1,s2,m,n-1), LCS(s1,s2,m-1,n));
}
void solve()
{
    string s1, s2;
    int m, n;
    cin>>s1>>s2;
    m=s1.length();
    n=s2.length();
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
