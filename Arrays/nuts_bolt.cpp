/*
Concept :-Quick Sort
Time :- 
*/

#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r, int pivot)
{
    int i=l-1;
    
    for(int j=l; j<r; j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
        else if(a[j]==pivot)
        {
            swap(a[j], a[r]);
        }
    }
    swap(a[i+1], a[r]);
    return i+1;
}

void q_sort(int a[], int b[], int l, int r)
{
    if(l<=r)
    {
        int p;
        
        p = partition(b, l, r, a[r]);
        partition(a, l, r, b[p]);
        
        q_sort(a, b, l, p-1);
        q_sort(a, b, p+1, r);
    }
}

void run_case()
{
	int n;
	cin>>n;
	int a[n], b[n];
	for(int i=0; i<n; i++)
	    cin>>a[i];
	for(int i=0; i<n; i++)
	    cin>>b[i];
	q_sort(a, b, 0, n-1);
	for(int i=0; i<n; i++)
	    cout<<a[i]<<" ";
	cout<<"\n";
	for(int i=0; i<n; i++)
	    cout<<b[i]<<" ";
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
7 
6 5 3 2 8 10 9
5 3 2 9 10 8 6
8 
10 9 8 7 4 70 60 50
50 9 60 8 10 4 70 7
*/
