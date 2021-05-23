//prefix sum

    for(int i=1; i<=1000; i++)
    {
        for(int j=2; j<=1000; j++)
        {
            m[i][j]+=m[i][j-1];
        }
    }

    for(int j=1; j<=1000; j++)
    {
        for(int i=2; i<=1000; i++)
        {
            m[i][j]+=m[i-1][j];
        }
    }
