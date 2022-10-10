//Binary search
//O(NlogM) Time (O(logM) for bin search in possible solns, N for array traversal each time.)
//O(1) Space
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int res=INT_MAX;

        while(low<=high){
            int mid=low+(high-low)/2;
            
            long long temp=0;
            for(int value:piles){
                temp+= ceil((double)value / mid);
            }
            
            if(temp<=h){
                res=min(res,mid);
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return res;
    }
};