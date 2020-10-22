//F[0]=0, F[1]=1, F[2]=1,....
//Tabulation(BottomUp)
#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    int bottomUp[n+1];
    bottomUp[0]=0;
    bottomUp[1]=1;
    for(int i=2; i<=n; i++)
    {
        bottomUp[i]=bottomUp[i-2]+bottomUp[i-1];   
    }
    return bottomUp[n];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<fib(n)<<"\n";
    }
    return 0;
}
