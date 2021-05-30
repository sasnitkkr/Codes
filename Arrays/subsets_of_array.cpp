/*

subset of {1, 2, 3} = subset of {1, 2} + append 3;
                    = {} {1} {2} {1, 2} {3} {1, 3} {2, 3} {1, 2, 3}
                    
T(n) = O(n^2)

*/

#include <bits/stdc++.h>
using namespace std;

void subset(vector<int>& v, int n, vector<vector<int>>& output)
{
    if(n==1)
    {
        vector<int> v1;
        vector<int> v2(1, v[n-1]);
        output.push_back(v1);
        output.push_back(v2);
        return;
    }
    subset(v, n-1, output);
    int cn=output.size(); // Important to store and use current n 
    for(int i=cn; i<2*cn; i++)
    {   
        vector<int> tmp(output[i%cn]);
        tmp.push_back(v[n-1]);
        output.push_back(tmp);
    }
}

void run_case()                                                            
{                                                           
    vector<vector<int>> output;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    subset(v, n, output);
    for(int i=0; i<output.size(); i++)
    {
        for(int j=0; j<output[i].size(); j++)
            cout<<output[i][j]<<" ";
        cout<<"\n";
    }
}                                       
                                                           
                                                           
int main()
{
   
                                                           
    int t=1;                                               
    //cin>>t;                                                
    while(t--)                                             
    {                                                      
        run_case();                                           
    }                                                      
    return 0;
}
