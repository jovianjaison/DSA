//Backtracking + Sort
//O(NlogN + N^(T/M + 1)) Time (Here M is the smallest element in the list and T is the target. T/M is height of imaginary n-ary tree and N^(T/M)+1 is the node count.)
//O(T/M) Space
class Solution {
public:
    set<string> s;
    vector<vector<int>> res;
    void backtrack(int id, vector<int>& candidates, int target, vector<int> curr, int currSum){
        
        if(currSum>target)return;
        if(currSum==target){
            res.push_back(curr);
        }

        for(int i=id;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            currSum+=candidates[i];
            backtrack(i,candidates,target,curr,currSum);
            currSum-=candidates[i];
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(0, candidates, target, {}, 0);
        return res;
    }
};