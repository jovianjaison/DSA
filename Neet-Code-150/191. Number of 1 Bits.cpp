//And with prev
//O(1) Time
//O(1) Space
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n){
            n&=(n-1);
            res++;
        }

        return res;
    }
};