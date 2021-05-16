#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x_power_n(int x, int n)
{
    long long y = 1;
    long long xm = x;
    while(n)
    {
        if(n&1)
        {
            y = y * xm;
        }
        xm = xm * xm;
        n>>=1;
    }
    return y;
}

void run_case()
{
    int x, n;
    cin>>x>>n;
    cout<<x_power_n(x, n)<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        run_case();
    }
    return 0;
}

/*
TCs

5
2 8
3 5
4 2
6 7
8 9
 
Exp Output
256
243
16
279936
134217728

*/
