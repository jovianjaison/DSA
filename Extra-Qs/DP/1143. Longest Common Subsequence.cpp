//Reference: https://www.youtube.com/watch?v=sSno9rV8Rhg&list=PLJULIlvhz0rE83NKhnq7acXYIeA0o1dXb&index=11

//Bottom up Tabular DP 
//O(m*n) Time
//O(m*n) Space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        return dp[m][n];
    }
};