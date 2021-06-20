#include<bits/stdc++.h>
using namespace std;

int merge(int a[], int l, int m, int r)
{
    int n1 = m-l+1, n2 = r-m, i=0, j=0;
    int L[n1], R[n2];
    
    while(i<n1)
    {   
        L[i]=a[l+i];
        i++;
    }
    while(j<n2)
    {
        R[j]=a[m+1+j];
        j++;
    }
    
    i=j=0; 
    int k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k++]=L[i++];    
        }
        else
        {
            a[k++]=R[j++];
        }
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}

void merge_sort(int a[], int l, int r)
{
    if(l<r)
    {
        int m = l+(r-l)/2;
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
        merge(a, l, m, r);
    }
}

void run_case()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	    cin>>a[i];
	
	merge_sort(a, 0, n-1);
	
	for(int i=0; i<n; i++)
	    cout<<a[i]<<" ";
	cout<<"\n";

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
/*
2
5 
1 4 2 5 3
8
1 7 4 6 3 2 5 8 
*/
