void sort012(int a[], int n)
    {
        // coode here 
        int i=0, j=0, k = n-1;
        while(j<=k) // Imp to check <'=' because after swapping a[j], a[k], a[j] maybe 0
        {
            if(a[j]==0)
            {
                swap(a[i], a[j]);
                i++;
                j++;
            }
            else if(a[j]==1) // else if is imp as we need to check j<=k every time
            {
                j++;
            }
            else if(a[j]==2)
            {
                swap(a[j], a[k]);
                k--;
            }
        }
    }
