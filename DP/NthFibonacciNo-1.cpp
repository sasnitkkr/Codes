//F0=0, F1=1, F2=1, F3=2,......
//CALCULATE nth fibonacci number
//Recursion
#include<bits/stdc++.h>
using namespace std;
int fib(int n)
{
    if(n==0 || n==1)
        return n;
    return fib(n-1)+fib(n-2);
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
