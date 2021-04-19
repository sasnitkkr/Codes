/*
Coins {2, 3, 5} Sum - 9
Possible ways { {2, 2, 5}, {2, 5, 2}, {5, 2, 2}, {2, 2, 2, 3}, {2, 2, 3, 2}, {2, 3, 2, 2} } 
Ans - > 8

Logic -> Try all combination
                  9 
       7          6         4
     5  4  2   4  3  1    2 1
   .............................
   f(n) = f(n-2) + f(n-3) + f(n-5) 

Time Complexity :- O(3^sum)
Space :- 
*/

#include <bits/stdc++.h>
using namespace std;                                                                                            
                                                           
int solution(int coin[], int n, int x)
{
    if(x ==0 ) return 1;

    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(x - coin[i]>=0)
            ans += solution(coin, n, x-coin[i]);
    }
    return ans;
}                                                           
                                                           
int main()
{
    int n, x;
    cin>>n>>x;
    int coin[n];
    for(int i=0; i<n; i++)
        cin>>coin[i];
    cout<<solution(coin,n,x);                                                     
 return 0;
}
