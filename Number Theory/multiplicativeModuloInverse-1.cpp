/*
  Basic Implementation

  (A.B)modulus m = 1 then B = ? is Multiplicative Modulo Inverse
  
  Note MMI is between [1, 2, 3, 4, ...,  m-1]
  
  Important MMI exists only if A and m are CO-PRIME (i.e. gcd(A,m) == 1 )
*/

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

int mmInverse(int a, int b)
{
    // Considering MMI exists
    triplet  ans = gcdExtended(a, b);
    return ans.x;
}
                                                           
int main()
{
    int a, b;
    cin>>a>>b;
    int ans = mmInverse(a,b);
    cout<<ans<<"\n";
                                                         
    return 0;
}

/* Test Cases 
1. 5 17
exp op :- 7
2. 5 12
exp op :- 5
3. 5 10 -> Invalid Input ∵ 5 and 10 are not co-prime 
*/
