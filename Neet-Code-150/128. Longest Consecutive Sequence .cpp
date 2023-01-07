//Hashmap with Intelligent Sequence building
//O(n) Time
//O(n) Space
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> um;

        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }

        int res=0;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(um.find(x-1)==um.end()){
                int curr=1;
                while(um.find(x+1)!=um.end()){
                    curr++;
                    x++;
                }
                res=max(res,curr);
            }
        }
        return res;
    }
};

//Union Find //TO improve:using ranking https://leetcode.com/problems/longest-consecutive-sequence/solutions/166544/union-find-thinking-process/?orderBy=most_votes&topicTags=union-find
//O(nlogn) Time
//O(n) Space
class UnionFind{
public:
vector<int> parent;
vector<int> rank;
    UnionFind(vector<int>& nums){
        int n=nums.size();
        parent.resize(n,-1);
        rank.resize(n,1);
        for(int i=0;i<nums.size();i++){
            parent[i]=i;
        }
    }

    void Union(int x, int y){
        int rootx = findParent(x);
        int rooty = findParent(y);

        if(rootx!=rooty){
            parent[rootx]=rooty;
            rank[rooty]+=rank[rootx];
        }
    }

    int findParent(int x){
        if(parent[x]!=x)
            parent[x]=findParent(parent[x]);
        
        return parent[x];
    }

    int findMax(){
        if(rank.size()==0)return 0;
        return *max_element(rank.begin(),rank.end());
    }
};

class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        UnionFind uf(nums);
        unordered_map<int,int> um;

        for(int i=0;i<nums.size();i++){
            if(um.find(nums[i])!=um.end())continue;

            if(um.find(nums[i]-1)!=um.end()){
                uf.Union(i,um[nums[i]-1]);
            }

            if(um.find(nums[i]+1)!=um.end()){
                uf.Union(i,um[nums[i]+1]);
            }

            um[nums[i]]=i;
        }

        return uf.findMax();
    }
};