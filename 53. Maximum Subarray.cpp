//Kadane
//O(n) Time
//O(1) Space
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=nums[0];
        int currSum=nums[0];

        for(int i=1;i<nums.size();i++){
            currSum=max(nums[i],currSum+nums[i]);
            res=max(currSum,res);
        }

        return res;
    }
};