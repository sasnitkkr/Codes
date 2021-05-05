/*
Time Complexity :- O(nlog(log√n))
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000
typedef long long ll;

bool prime[MAX+1];

int main() {
	
  // Special -> 0, 1
	prime[0]=prime[1]=false;
  //Initialise all to true
	for(int i=2; i<=MAX; i++)
	    prime[i]=true;
  // (ll)i*i, (ll)i*i, 
	for(int i=2; (ll)i*i<=MAX; i++)
	{
	    if(prime[i])
	        for(int k = i*i; k<=MAX; k+=i)
	            prime[k]=false;
	}
    
    // print all prime numbers <=MAX
    for(int i=1; i<=500; i++)
        if(prime[i]) cout<<i<<" ";
    cout<<"\n";
	
	return 0;
}
