/*
  Given n
  find no. of divisors of n!
  if I express n! ans -> 2^p * 3^q * 5^r * ...... * m^k
  then no of divisors are (p+1)(q+1)(r+1)...(k+1)
  
  each prime number, p find the largest power of it that divides n!
  To find p q r use Legendre’s formula ⌊n/p⌋ + ⌊n/(p^2)⌋ + ⌊n/(p^3)⌋ + …… to find r in (prime_no)^r -> Works for factorial only
*/
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define MAX 50000
typedef long long ll;

bool prime[MAX+1];

int divisors(int n)
{
    ll ans = 1;
    vector<int> v;
    for(int i=2; i<=n; i++)
    {
        if(prime[i])
            v.push_back(i);
    }
    for(int i=0; i<v.size(); i++)
    {
        ll t = v[i];
        ll count=0;
        while(t<=n)
        {
            count = (count + (n/t))%mod;
            t=t*v[i];
        }
        ans = (ans*(count+1))%mod;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    cout<<divisors(n)<<"\n";
}

int main(){
	// Write your code here
    int t;
    cin>>t;
    //Sieve
    prime[0]=prime[1]=false;
    for(int i=2; i<=MAX; i++)
        prime[i]=true;
	  for(int i=2; (ll)i*i <= MAX; i++)
    {
        if(prime[i])
            for(int k=i*i; k<=MAX; k+=i)
            	prime[k]=false;
    }
    //Sieve
    while(t--)
    {
        solve();
    }
	return 0;
}
