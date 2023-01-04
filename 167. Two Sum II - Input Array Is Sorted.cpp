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

//Binary Search
//O(nlogn) Time
//O(1) Space
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        
        for(int i=0;i<n;i++){
            int low=i+1;
            int high=n-1;
            int bsTarget=target-numbers[i];
            while(low<=high){
                int mid = low+(high-low)/2;
                if(numbers[mid]==bsTarget){
                    return {i+1,mid+1};
                }else if(numbers[mid]>bsTarget){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
        }
        return {};
    }
};