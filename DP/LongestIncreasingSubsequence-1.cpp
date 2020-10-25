/**Special Tabulation Like Method*
Consider all increasing subsequences ending with a[i] (&& a[i]<a[j])
Time:- ϑ(n^2)
Auxilary Space:-ϑ(n)
*/

#include<bits/stdc++.h>
using namespace std;
int LIS(int a[], int n)
{
    //lis[i] stores longest increasing subsequence ending with a[i];
    int lis[n];
    lis[0]=1;
    for(int i=1; i<n; i++)
    {
        lis[i]=1;
        for(int j=0; j<i; j++)
        {
            if(a[j]<a[i])
            {
                lis[i]=max(lis[j]+1,lis[i]);
            }
        }
    }
    int res=lis[0];
    for(int i=1; i<n; i++)
    {
        if(lis[i]>res)
            res=lis[i];
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<LIS(a,n)<<"\n";
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
/*TesT Cases
6
4
3 10 2 8
7
3 4 2 8 10 5 1
5
3 4 2 8 10
8
4 10 6 5 8 11 2 20
3
10 20 30
3
30 20 10*/
