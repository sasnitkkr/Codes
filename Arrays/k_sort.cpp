/*
Concept :- Heap Sort
Time :- O(nlogk)
*/

#include<bits/stdc++.h>
using namespace std;

void k_sort(int a[], int n, int k)
{
    // insert k+1 ele in heap
	priority_queue<int, vector<int>, greater<int> > pq(a, a+k+1); 
	int index = 0;
	//n-k-1 elements at correct position
	for(int i=k+1; i<n; i++)
	{
	    a[index++] = pq.top();
	    pq.pop();
	    pq.push(a[i]);
	}
	//for remaining
	while(!pq.empty())
	{
	    a[index++] = pq.top();
	    pq.pop();
	}
}

void run_case()
{
	int n, k;
	cin>>n>>k;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	k_sort(a, n, k);
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
Test Cases
2
7 3
6 5 3 2 8 10 9
8 4
10 9 8 7 4 70 60 50
*/
