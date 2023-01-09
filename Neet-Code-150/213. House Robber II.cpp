//DP
//O(n) Time
//O(1) Space 
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];

        int a = 0;
        int b = 0;
        for(int i=0;i<nums.size()-1;i++){
            int c = max(nums[i]+a,b);
            a = b;
            b = c;
        }
        int res = max(a,b);

        a = 0;
        b = 0;
        for(int i=1;i<nums.size();i++){
            int c = max(nums[i]+a,b);
            a = b;
            b = c;
        }
        return max(res,max(a,b));
    }
};