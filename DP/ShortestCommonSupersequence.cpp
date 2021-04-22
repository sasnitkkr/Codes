/*
Source :- https://leetcode.com/problems/shortest-common-supersequence/
          https://youtu.be/pHXntFeu6f8
*/

/* Returns LCS string */
string LCS(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++)
        dp[i][0] = 0;
    for(int i=1; i<=n; i++)
        dp[0][i] = 0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=m, j=n; 
    string ans;
    while(i>=1 && j>=1)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i--;  // Important to change pointers
            j--;
        }
        else
        {
            if(dp[i-1][j]==dp[i][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end()); // Important to reverse
    return ans;
}

/* Returns SCS string */
string shortestCommonSupersequence(string s1, string s2) {
  
    string s3 = LCS(s1,s2);
    string ans;
  
    int i=0, j=0, k=0;
    int m = s1.length(), n = s2.length(); 
  
    /* Use 3 pointer approach */
    while(k<s3.length())
    {
        char c = s3[k];
        while(i<m && s1[i]!=c)
        {
            ans.push_back(s1[i]);
            i++;
        }
        while(j<n && s2[j]!=c)
        {
            ans.push_back(s2[j]);
            j++;
        }
        ans.push_back(c);
        i++; j++; k++;
    }
    while(i<m) // Directly add wo check
    {
        ans.push_back(s1[i]);
        i++;
    }
    while(j<n)
    {
        ans.push_back(s2[j]);
        j++;
    }
    return ans;
}

int main()
{
  string s1, s2;
  cin>>s1>>s2;
  cout<<shortestCommonSupersequence(s1, s2)<<"\n";
}

/* Test Cases 
abac 
cab
o/p :- cabac
*/
