#include <bits/stdc++.h>
using namespace std;
                                                         
int gcdExtended(int a, int b, int* x, int* y) // returns gcd, updates x, y
{                  
    // Base case
    
    if(a==0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    
    // Extended Euclid Algorithm 
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    
    *x = y1 - (b/a)*x1;
    *y = x1;
    
    return gcd;
}                                                           
                                                           
                                                           
int main()
{
    int a, b, x, y;
    cin>>a>>b;
    
    //int gcd = gcdExtended(a, b, &x, &y);
    //cout<<gcd<<" "<<x<<" "<<y<<" ";
    
    //cout<<gcdExtended(a, b, &x, &y)<<" "<<x<<" "<<y<<" ";
                                                         
    return 0;
}

/* Test Cases 
1. 16 10
exp op :- 2 2 -3
2. 15 10
exp op :- 5 1 -1 
 */
