#include <bits/stdc++.h>
using namespace std;
              
struct triplet{
  int gcd;
  int x;
  int y;
};               
                                                         
triplet gcdExtended(int a, int b) // returns gcd, updates x, y
{                  
    // Base case
    
    if(a==0)
    {
        triplet ans;
        ans.x = 0;
        ans.y = 1;
        ans.gcd = b;
        return ans;
    }
    
    // Extended Euclid Algorithm 
    
    triplet tmp = gcdExtended(b%a, a);
    triplet ans;
    
    int x1 = tmp.x;
    int y1 = tmp.y;
    
    ans.x = y1 - (b/a)*x1;
    ans.y = x1;
    ans.gcd = tmp.gcd;
    
    return ans;
}                                                           
                                                           
                                                           
int main()
{
    int a, b;
    cin>>a>>b;
    triplet ans = gcdExtended(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<"\n";
                                                         
    return 0;
}

/* Test Cases */
1. 16 10
exp op :- 2 2 -3
2. 15 10
exp op :- 5 1 -1
