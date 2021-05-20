#include <bits/stdc++.h>
using namespace std;

//O(1)
int findMedian(vector<int> v, int l, int r)
{
    int m=l+(r-l)/2;
    return v[m];
}
//O(n)
int m_o_m(vector<int> a, int l, int r)
{
    int n=r-l+1, i;
    if(n==1) return a[l];
    //(n/5)5log5-> nlog5
    for(i=l; i+4<=r; i+=5)
    {
        sort(a.begin()+i,a.begin()+i+5);
    }
    if(i<=r)
        sort(a.begin()+i,a.begin()+r+1);
    //O(n/5)
    vector<int> m(ceil(n/5.0));
    int k=0;
    for(i=l; i+4<=r; i+=5)
    {
        m[k++]=findMedian(a,i,i+4);
    }
    if(i<=r)
    {
        m[k]=findMedian(a,i,r);
    }
    return m_o_m(m,0,(ceil(n/5.0))-1);
}
int partition(vector<int> &v, int l, int r, int pivot)
{
    int i=l-1;
    for(int j=l; j<=r-1; j++)
    {
        if(v[j]<pivot)
        {
            i++;
            swap(v[i],v[j]);
        }
        else if(v[j]==pivot)
        {
            swap(v[j],v[r]);
            j--;
        }
    }
    i++;
    swap(v[i],v[r]);
    return i;
}

//O(n)
int kthSmallest(vector<int> a, int l, int r, int k)
{
    int pivot=m_o_m(a,l,r);//O(n)
    int pi=partition(a,l,r,pivot);//O(n)
    if(pi==k-1) return a[pi];
    else if(pi>k-1) return kthSmallest(a,l,pi-1,k);
    else return kthSmallest(a,pi+1,r,k);
}                                                           
                                                            
int main()
{                                              
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; i++) cin>>a[i];
        cin>>k;
        cout<<kthSmallest(a,0,n-1,k)<<"\n";
    }
                                                           

    return 0; 
}
