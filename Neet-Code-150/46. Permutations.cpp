//Backtracking without hashmap
//O(~n!) Time
//O(n!) Space
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int id,vector<int>& nums){
        if(id==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=id;i<nums.size();i++){
            swap(nums[id],nums[i]);
            backtrack(id+1,nums);
            swap(nums[id],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0,nums);
        return ans;
    }
};

//Backtracking with hashmap
//O(~n!) Time
//O(n!) Space
class Solution {
public:
    unordered_map<int,int> um;
    vector<vector<int>> res;
    vector<int> curr;
    void backtrack(vector<int>& nums){
        if(curr.size()==nums.size())
            res.push_back(curr);
        
        for(int i=0;i<nums.size();i++){
            if(um.find(nums[i])==um.end()){
                um[nums[i]]++;
                curr.push_back(nums[i]);
                backtrack(nums);
                curr.pop_back();
                um.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return res;
    }
};