//Refer: TechDose : https://www.youtube.com/watch?v=ZI17bgz07EE

//Tabular DP | 0/1 Knapsack variation
//O(m*n) Time Time m=No. of possible coins, n=Subset sum / Required amount
//O(m*n) Space 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp;

        dp.resize(n+1,vector<int>(amount+1,0));
        dp[0][0]=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0 && j!=0)
                    dp[i][j]=1e5;
                else if(j==0)
                    dp[i][j]=0;
                else if(coins[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
        }

        return dp[n][amount]==1e5?-1:dp[n][amount];
    }
};

//Backtracking TLE
//O(n^m) Time
//O(m) Space 
class Solution {
public:
    int res=INT_MAX;
    int n;
    int backtrack(int id, vector<int>& coins, int amount){
        
        //cout<<id<<" "<<amount<<"\n";

        if(amount==0){
            return 0;
        }

        if(id>=n)return INT_MAX;

        if(coins[id]>amount)
            return backtrack(id+1,coins,amount);
        else{
            int it1=backtrack(id+1,coins,amount);
            int it2=backtrack(id,coins,amount-coins[id]);

            if(it1>it2 && it2!=INT_MAX)
                return it2+1;
            else
                return it1;
        }

    }

    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        sort(coins.begin(),coins.end(),greater<int>());

        int res=backtrack(0,coins,amount);
        return res==INT_MAX?-1:res;
    }
};