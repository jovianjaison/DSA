//Reference: https://www.youtube.com/watch?v=nLmhmB6NzcM&list=PLJULIlvhz0rE83NKhnq7acXYIeA0o1dXb&index=6

//Bottom up Tabular DP (Space optimized)
//O(n*w) Time
//O(w) Space
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(3,vector<int>(w+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 && j!=0)
                dp[1][j] = 0;
            else if(j==0)
                dp[1][j] = 0;
            else if(j<weights[i-1])
                dp[1][j] = dp[0][j];
            else
                dp[1][j] = max(dp[0][j],dp[0][j-weights[i-1]]+values[i-1]);
        }
        dp[0]=dp[1];
        dp[1].resize(w+1,0);
    }


    return dp[0][w];
}

//Bottom up Tabular DP
//O(n*w) Time
//O(n*w) Space
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 && j!=0)
               dp[i][j] = 0;
            else if(j==0)
               dp[i][j] = 0;
            else if(j<weights[i-1])
               dp[i][j] = dp[i-1][j];
            else
               dp[i][j] = max(dp[i-1][j],dp[i-1][j-weights[i-1]]+values[i-1]);
        }
    }
    
    
    return dp[n][w];
}