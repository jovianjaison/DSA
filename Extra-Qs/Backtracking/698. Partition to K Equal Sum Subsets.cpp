//Refer NeetCode: https://www.youtube.com/watch?v=mBk4I0X46oI

//Backtracking with memoization
//O(k * 2^N) Time
//O(N) Space
class Solution {
public:
    unordered_map<string, bool> um;
    string considered;
    int targetSum=0;
    int n;
    bool backtrack(int id, vector<int>& nums, int k, int sum){
        if(k==0)return true;

        if (um.find(considered) != um.end()) {
            return um[considered];
        }

        if(sum==targetSum){
            return um[considered]=backtrack(0,nums,k-1,0);
        }

        

        for(int i=id;i<n;i++){
            if(considered[i]=='1' || sum+nums[i]>targetSum)continue;
            considered[i]='1';
            if(backtrack(i+1,nums,k,sum+nums[i]))
                return true;
            considered[i]='0';
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        for (int i = 0; i < n; i++) {
             targetSum += nums[i];
        }

        if(targetSum%k!=0)return false;
        sort(nums.begin(),nums.end(),greater<int>());
        targetSum/=k;
        

        considered.resize(n,'0');
        return backtrack(0, nums,k,0);
    }
};

//Backtracking
//O(N * 2^N) Time
//O(N * 2^N) Space
class Solution {
public:
    vector<bool> considered;
    int targetSum;
    int n;
    bool backtrack(int id, vector<int>& nums, int k, int sum){
        if(k==0)return true;
        if(sum==targetSum){
            return backtrack(0,nums,k-1,0);
        }

        for(int i=id;i<n;i++){
            if(considered[i] || sum+nums[i]>targetSum)continue;
            considered[i]=true;
            if(backtrack(i+1,nums,k,sum+nums[i]))
                return true;
            considered[i]=false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        targetSum = accumulate(nums.begin(),nums.end(),0);

        if(targetSum%k!=0)return false;
        sort(nums.begin(),nums.end(),greater<int>());
        targetSum/=k;
        n=nums.size();

        considered.resize(n,false);
        return backtrack(0, nums,k,0);
    }
};