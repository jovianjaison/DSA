//Greedy Forward
//O(n) Time
//O(1) Space
//https://leetcode.com/problems/jump-game-ii/solutions/1192401/easy-solutions-w-explanation-optimizations-from-brute-force-to-dp-to-greedy-bfs/
//Ref soln 4 for diagram
class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJump=nums[0];
        int prevJump=0;
        if(nums.size()==1)return 0;

        int n=nums.size();
        int res=0;

        for(int i=0;i<n;i++){
            maxJump=max(maxJump,i+nums[i]);
            if(i==prevJump){
                prevJump=maxJump;
                res++;
            }
            if(prevJump>=n-1)return res;
        }

        return res;
    }
};

//DP Forward
//O(n^2) Time
//O(1) Space
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX-1);
        dp[0]=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n&&j<i+1+nums[i];j++){
                dp[j]=min(dp[j],dp[i]+1);
            }
        }

        return dp[n-1];
    }
};