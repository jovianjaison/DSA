//Greedy
//O(n) Time
//O(1) Space
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int resIndex=0;
        int surplus=0;
        int totalSurplus=0;

        for(int i=0;i<gas.size();i++){
            surplus+=gas[i]-cost[i];
            totalSurplus+=gas[i]-cost[i];

            if(surplus<0){
                surplus=0;
                resIndex=i+1;
            }
        }

        return totalSurplus<0?-1:resIndex;
    }
};