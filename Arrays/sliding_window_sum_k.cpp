#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int max_k(int a[], int n, int k)
{
    int i=0, j=0;
    int ans = INT_MIN;
    int sum = 0;
    while(j<n)
    {
        sum+=a[j];
        if(j-i+1<k)
        {
            j++;
        }
        else if(j-i+1==k)
        {
            ans = max(ans, sum);
            sum-=a[i];
            i++;
            j++;
        }
    }
    return ans;
}

void run_case() 
{
    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    cout<<max_k(a, n, k)<<"\n";
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
