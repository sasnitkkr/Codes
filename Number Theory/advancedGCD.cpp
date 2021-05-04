/*
    Advanced GCD
    gcd(a, b)
    a -> 40,000
    b -> 10^250
    Now, gcd(a,b) = gcd(b%a, a) -> problem solved as now both are integer
    
    Now, how to take b mod a
    b might be in a string
    
    23567 mod m = ((2356*10)mod m + 7 mod m) mod m
    
    ans = 0;
    for(each c : str)
        ans = (ans*10 % m + c %m ) %m;
*/
#include<bits/stdc++.h>
using namespace std;

//O(log(max(a,b)))
int gcd(int a, int b)
{
    if(a==0)
        return b;
    return gcd(b%a, a);
}

// can convert if m!=0
int convert(string s, int m)
{
    long long ans = 0;
    for(int i=0; i<s.length(); i++)
    {
        int current_digit = s[i]-'0'; 
        ans = ((ans*10)%m + current_digit%m)%m;
    }
    return ans;
}

int main(){
	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        string b;
        cin>>a>>b;
        // covert b to b mod a
        if(a!=0)
        {
            int new_b = convert(b, a);
            cout<<gcd(a, new_b)<<"\n";
        }
        else
        {
            cout<<b<<"\n";
        }
    }
	return 0;
}
