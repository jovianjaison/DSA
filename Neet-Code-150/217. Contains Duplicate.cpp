//Hashmap
//O(n) Time
//O(n) Space
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto num:nums){
            if(um.find(num)!=um.end()){
                return true;
            }else{
                um[num]++;
            }
        }
        return false;
    }
};

//Sorting
//O(nlogn) Time
//O(1) Space
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])return true;
        }

        return false;
    }
};