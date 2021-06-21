int first(int a[], int lo, int hi, int ele)
{
    if(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if((mid==0||a[mid-1]<ele)&&a[mid]==ele)
            return mid;
        else if(a[mid]>=ele)
            return first(a, lo, mid-1, ele);
        else
            return first(a, mid+1, hi, ele);
    }
    return -1;
}
int last(int a[], int n, int lo, int hi, int ele)
{
    if(lo<=hi)
    {
        int mid = lo+(hi-lo)/2;
        if((mid==n-1||a[mid+1]>ele) && a[mid]==ele)
            return mid;
        else if(a[mid]<=ele)
            return last(a, n, mid+1, hi, ele);
        else 
            return last(a, n, lo, mid-1, ele);
    }
    return -1;
}

vector<int> find(int arr[], int n , int x )
{
    // code here
    int f = first(arr, 0, n-1, x);
    int l = last(arr, n, 0, n-1, x);
    vector<int> res = { f, l};
    return res;
}
