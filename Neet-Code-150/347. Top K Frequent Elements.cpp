//Hashmap + Buckets
//O(n) Time
//O(n) Space
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
       
        vector<vector<int>> buckets(nums.size()+1,vector<int>());
        vector<int> res;
        for(int num:nums){
            um[num]++;
        }

        for(auto item:um){
            buckets[item.second].push_back(item.first);
        }

        for(int i=nums.size();i>=0;i--){
            for(int j=0;j<buckets[i].size();j++){
                res.push_back(buckets[i][j]);
                if(res.size()>=k)return res;
            }
        }
        return res;
    }
};

//Hashmap + Max heap
//O(nlogk) Time (where k is size of priority queue = given q)
//O(n) Space
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        auto comp = [&um](int n1, int n2){return um[n1]>um[n2];};
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        vector<int> res;
        for(int num:nums){
            um[num]++;
        }

        for(auto item:um){
            pq.push(item.first);
            if(pq.size()>k)pq.pop();;
        }

        for(int i=0;i<k;i++){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

//Hashmap + Vector sorting
//O(nlogn) Time
//O(n) Space
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        vector<pair<int,int>> vec;
        vector<int> res;
        for(int num:nums){
            um[num]++;
        }

        for(auto item:um){
            vec.push_back({item.second,item.first});
        }

        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        for(int i=0;i<vec.size()&&i<k;i++){
            res.push_back(vec[i].second);
        }
        return res;
    }
};