//Iterate
//O(1) Time
//O(1) Space
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m=0;
        for(int i=0;i<32;i++){
            m<<=1;
            m|=(n&1);
            n>>=1;
        }

        return m;
    }
};