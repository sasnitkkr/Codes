#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll power(ll x, ll n, ll m)
{ 
    if (!n) return 1 % m; // n=0
    if (n & 1) return power(x, n - 1, m) * x % m; // n->odd
    ll res = power(x ,n >> 1, m);
    return (res*res) % m;
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
