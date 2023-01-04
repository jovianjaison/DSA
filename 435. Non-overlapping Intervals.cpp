//Greedy
//O(nlogn) Time
//O(1) Space
class Solution {
public:
    static bool sortcol( const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
        sort(intervals.begin(),intervals.end(),sortcol);

        int n=intervals.size();
        int res=1;
        int prevFinish=intervals[0][1];

        for(int i=1;i<n;i++){
            if(prevFinish<=intervals[i][0]){
                prevFinish=intervals[i][1];
                res++;
            }
        }

        return n-res;
    }
};

//DP
//O(n^2) Time
//O(n) Space
class Solution {
public:
    static bool sortcol( const vector<int>& v1, const vector<int>& v2 ) {
        return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
        sort(intervals.begin(),intervals.end(),sortcol);

        int n=intervals.size();
        vector<int> vec(n,0);
        int res=INT_MIN;

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<i;j++){
                if(intervals[j][1]<=intervals[i][0])
                    count=max(count,vec[j]);
            }
            
            vec[i]=count+1;
            res=max(res,vec[i]);
        }
        return n-res;
    }
};

//Bruteforce 
//O(2^n) Time
//O(n) Space
class Solution {
public:
    int check(int prev, int curr, vector<vector<int>>& intervals) {
        if(curr==intervals.size())return 0;

        int taken=INT_MAX;
        int notTaken;
        if(prev==-1 || intervals[prev][1]<=intervals[curr][0]){
            taken = check(curr,curr+1,intervals);
        }
        notTaken = check(prev,curr+1,intervals)+1;
        return min(taken,notTaken);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        return check(-1,0,intervals);
    }
};