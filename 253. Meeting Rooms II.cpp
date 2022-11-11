//Sorting + Minheap
//O(nlogn) Time 
//O(n) Space
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            if(!pq.empty() && intervals[i][0]>=pq.top())
                pq.pop();
            
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};

//Sorting + 2 pointer
//O(nlogn) Time 
//O(n) Space
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> startT;
        vector<int> endT;
        int res=0;
        for(int i=0;i<intervals.size();i++){
            startT.push_back(intervals[i][0]);
            endT.push_back(intervals[i][1]);
        }

        sort(startT.begin(),startT.end());
        sort(endT.begin(),endT.end());

        int ptrStart=0;
        int ptrEnd=0;
        while(ptrStart<intervals.size()){
            if(startT[ptrStart]<endT[ptrEnd])
                res++;
            else
                ptrEnd++;
            

            ptrStart++;
        }

        return res;
    }
};

//Sorting + Interval expansion
//O(nlogn + n^2) Time 
//O(n) Space
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> vec;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            bool flag=false;
            for(int j=0;j<vec.size();j++){
                if(vec[j]<=intervals[i][0]){
                    flag=true;
                    vec[j]=intervals[i][1];
                    break;
                }
            }
            if(!flag)
                vec.push_back(intervals[i][1]);
        }
        return vec.size();
    }
};