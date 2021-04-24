How to solve a dp Question

1. recursive function
2. base condition 


/* HOW TO GET DP ARRAY IN MEMOIZATION */

1. dp[1001] or dp[1001][1001] + memset
2. vector<vector<int> > dp(n, vector<int> (n,-1)); -> in case you are given Solution class and you pass dp arrry in function -> less memory for function in stack => USE vector and pass by reference

int dp[1001] / int dp[1001][1001]

in int main()
{
  // Do memset before each call of function
  // NOTE : dp array need to be -1 before each test case as it is global
  memset(dp,-1,sizeof(dp));
}


