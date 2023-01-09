//Iteration 
//O(n) Time
//O(n) Space 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size();

        for(int i=0;i<n;i++){
            if(newInterval[1]<intervals[i][0]){
                res.push_back(newInterval);
                for(int j=i;j<n;j++){
                    res.push_back(intervals[j]);
                }
                return res;
            }else if(newInterval[0]>intervals[i][1]){
                res.push_back(intervals[i]);
            }else{
                newInterval = {min(intervals[i][0],newInterval[0]),max(intervals[i][1],newInterval[1])};
            }
        }
        
        res.push_back(newInterval);
        return res;
    }
};