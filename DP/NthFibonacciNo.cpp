//F0=0, F1=1, F2=1, F3=2,......
//CALCULATE nth fibonacci number
//Memoisation(TopDown)
#include<bits/stdc++.h>
using namespace std;
int memo[1000];
int fib(int n)
{
    if(n==0 || n==1)
        return n;
    if(memo[n]==-1)
    {
        int res;
        res=fib(n-1)+fib(n-2);
        memo[n]=res;
    }
    return memo[n];
}
int main()
{
    int n;
    cin>>n;
    memset(memo,-1, sizeof(memo));
    cout<<fib(n);
    return 0;
}
