//DP
//O(n) Time
//O(1) Space 
class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for(int i=0;i<nums.size();i++){
            int c = max(nums[i]+a,b);
            a = b;
            b = c;
        }
        return max(a,b);
    }
};