//Backtracking
//O(n 2^n) Time (2^n for backtracking, n for adding curr to res vector deep copy)
//O(n) Space
class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;
    void backtrack(int id, vector<int>& nums){
        res.push_back(curr);

        for(int i=id;i<nums.size();i++){
            if(i!=id && nums[i]==nums[i-1])continue;            
            curr.push_back(nums[i]);
            backtrack(i+1,nums);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,nums);

        return res;
    }
};