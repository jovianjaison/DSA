//Refer: TechDose : https://www.youtube.com/watch?v=34l1kTIQCIA, https://www.youtube.com/watch?v=obhWqDfzwQQ

//0/1 Knapsack DP Tabulation / Bottom up DP
//O(m*n) Time m=No. of elements, n=Subset sum / Required sum
//O(m*n) Space
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        
        int n=nums.size();
        sum/=2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));

        dp[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0 && j!=0)
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
                else if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else if(nums[i-1]==j)
                    dp[i][j]=true;
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        
        return dp[n][sum];
    }
};

//Subset Sum / Top-Down DP with memoization
//O(m*n) Time
//O(m*n) Space
class Solution {
public:
    vector<vector<optional<bool>>> dp;
    int N;
    bool subsetSum(vector<int>& nums, int id, int sum){
        if(sum==0)return true;
        else if(id>=N || sum<0)return false;
        
        if(dp[id][sum]!=nullopt)
            return dp[id][sum]==true;

        dp[id][sum] = subsetSum(nums,id+1,sum) || subsetSum(nums,id+1,sum-nums[id]);

        return dp[id][sum]==true;
    }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;
        
        int n=nums.size();
        N=n;
        sum/=2;
        dp.resize(n+1,vector<optional<bool>>(sum+1,nullopt));
        return subsetSum(nums, 0, sum);
    }
};

//Bruteforce
//O(2^N) Time
//O(N) Space
class Solution {
public:
    bool backtrack(vector<int>& nums, int id, int sum){
        if(sum==0)return true;
        if(id==0)return false;

        return backtrack(nums,id-1,sum) || backtrack(nums,id-1,sum-nums[id]);
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)return false;

        return backtrack(nums, nums.size()-1, sum/2);
    }
};
