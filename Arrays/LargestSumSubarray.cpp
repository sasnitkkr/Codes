#include<bits/stdc++.h>
using namespace std;
// Function to find subarray with maximum sum
//Time Complexity :- O(n)
//Space Complexity :- O(1)
int maxSubarraySum(int arr[], int n)
{
    int max_end_here=0, best_so_far=INT_MIN;
    for(int i=0; i<n; i++)
    {
        max_end_here=max_end_here+arr[i];
        if(best_so_far<max_end_here)
            best_so_far=max_end_here;
        if(max_end_here<0)
            max_end_here=0;
    }
    return best_so_far;
}

int main()
{
    int t,n;
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {  
        cin>>n; //input size of array
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        cout << maxSubarraySum(a, n) << endl;
    }
}
