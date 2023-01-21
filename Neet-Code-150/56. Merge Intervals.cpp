//Sorting
//O(nlogn) Time
//O(n) Space
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0)return {{}};

        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(res[res.size()-1][1]>=intervals[i][0]){
                res[res.size()-1][1] = max(res[res.size()-1][1],intervals[i][1]);
            }else{
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};