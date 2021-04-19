#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <bits/stdc++.h>
using namespace std;                                                        
#define mod 1000000007
typedef long long ll;

vector<int> dp(1000000);                                                           

int solution(int coin[], int n, int x)
{
    if(x == 0) return 1;
    
    if(dp[x]==-1)
    {
        ll ans = 0;
        for(int i=0; i<n; i++)
        {
            if(coin[i]<=x)
                ans =( ans + solution(coin, n, x-coin[i]) ) % mod;
        }
        dp[x]=ans;
    }
    return dp[x];
}                                                           
                                                           
int main()
{
    SPEED
                                                           
                                                           
    int n, x;
    cin>>n>>x;
    int coin[n];
    for(int i=0; i<n; i++)
        cin>>coin[i];
    fill(dp.begin(), dp.begin()+x+1, -1);
    cout<<solution(coin, n, x);                                                      
 return 0;
}
