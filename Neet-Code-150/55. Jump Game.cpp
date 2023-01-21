//Greedy Forward
//O(n) Time
//O(1) Space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump=nums[0];
        int n=nums.size();

        for(int i=0;i<=maxJump;i++){
            if(maxJump>=(n-1))return true;
            
            maxJump=max(maxJump,i+nums[i]);
        }

        return false;
    }
};

//Related solutions below:

//Greedy Reverse
//O(n) Time
//O(1) Space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size()-1;
        int latestValid=n;
        for(int i=n-1;i>=0;i--){
            if(i+nums[i]>=latestValid)
                latestValid=i;
        }

        return latestValid==0;
    }
};

//Bottom-up DP
//O(n^2) Time
//O(n) Space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> memo(n,false);
        memo[n-1]=true;

        for(int i=n-2;i>=0;i--){
            int steps=i+nums[i];
            for(int j=i+1;j<=steps&&j<n;j++){
                if(memo[j]==true){
                    memo[i]=true;
                    break;
                }
            }
        }

        return memo[0];
    }
};

//Top-down DP
//O(n^2) Time
//O(n) Space
class Solution {
public:
    int n;
    vector<int> memo;
    bool backtrack(int id, vector<int>& nums){
        if(memo[id]!=-1)return memo[id]==1?true:false;
        int steps=id+nums[id];
        for(int i=min(n-1,steps);i>id;i--){
            if(backtrack(i,nums)){
                memo[id]=1;
                return true;
            }
        }
        memo[id]=0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        n=nums.size();
        memo.resize(n,-1);
        memo[n-1]=true;
        return backtrack(0,nums);
    }
};

//Backtracking
//O(2^n) Time
//O(n) Space
class Solution {
public:
    int n;
    bool backtrack(int id, vector<int>& nums){
        if(id==n-1)return true;

        int steps=id+nums[id];
        for(int i=min(n-1,steps);i>id;i--){
            if(backtrack(i,nums))return true;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        n=nums.size();
        return backtrack(0,nums);
    }
};