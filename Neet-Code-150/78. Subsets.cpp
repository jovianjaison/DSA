//Backtracking
//O(N*2^N) Time
//O(N) Space
class Solution {
public:
    vector<vector<int>> res;
    int N;
    void backtrack(int id, vector<int>& nums, vector<int>& curr){
        res.push_back(curr);
        for(int i=id;i<N;i++){
            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        N=nums.size();
        vector<int> curr;
        backtrack(0,nums,curr);
        return res;
    }
};