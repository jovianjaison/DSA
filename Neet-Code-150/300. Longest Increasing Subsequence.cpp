//Subsequence Building + Binary Search
//O(nlogn) Time
//O(n) Space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> bucket;
        bucket.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]>bucket[bucket.size()-1]){
                bucket.push_back(nums[i]);
            }else{
                int low=0;
                int high=bucket.size();
                while(low<=high){
                    int mid=low+(high-low)/2;

                    if(bucket[mid]>=nums[i]){
                        high=mid-1;
                    }else{
                        low=mid+1;
                    }
                }
                swap(nums[i],bucket[low]);
            }
        }
        return bucket.size();
    }
};

//Subsequence Building
//O(n^2) Time (Best and Avg case efficient than lower method)
//O(n) Space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> bucket;
        bucket.push_back(nums[0]);

        for(int i=1;i<nums.size();i++){
            if(nums[i]>bucket[bucket.size()-1]){
                bucket.push_back(nums[i]);
            }else{
                for(int j=0;j<bucket.size();j++){
                    if(bucket[j]>=nums[i]){
                        bucket[j]=nums[i];
                        break;
                    }
                }
            }
        }
        return bucket.size();
    }
};

//Bottom up Tabular DP 
//O(n^2) Time
//O(n) Space
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    dp[i]=max(dp[i],1+dp[j]);
            }
        }

        return *max_element(dp.begin(),dp.end());
    }
};