//Two pointer
//O(n) Time
//O(1) Space
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1 = 0;
        int ptr2 = numbers.size()-1;

        while(ptr1<ptr2){
            if(target-numbers[ptr2]==numbers[ptr1]){
                return {ptr1+1,ptr2+1};
            }else if(target-numbers[ptr2]<numbers[ptr1]){
                ptr2--;
            }else{
                ptr1++;
            }
        }

        return {};
    }
};