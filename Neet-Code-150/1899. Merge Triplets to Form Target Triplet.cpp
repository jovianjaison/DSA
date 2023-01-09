//Greedy - OnePass
//O(n) Time
//O(1) Space
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool f=false;
        bool s=false;
        bool t=false;

        for(auto triplet:triplets){
            if(triplet[0]==target[0] && triplet[1]<=target[1] && triplet[2]<=target[2])
                f=true;

            if(triplet[1]==target[1] && triplet[0]<=target[0] && triplet[2]<=target[2])
                s=true;
            
            if(triplet[2]==target[2] && triplet[1]<=target[1] && triplet[0]<=target[0])
                t=true;

            if(f==true && s==true && t==true)return true;
        }

        return false;
    }
};

//Greedy - OnePass
//O(n) Time
//O(1) Space
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> prev = {0,0,0};
        for(auto triplet:triplets){
            if(triplet[0]<=target[0] && triplet[1]<=target[1] && triplet[2]<=target[2]){
                prev[0]=max(prev[0],triplet[0]);
                prev[1]=max(prev[1],triplet[1]);
                prev[2]=max(prev[2],triplet[2]);
            }
        }

        if(prev[0]==target[0] && prev[1]==target[1] && prev[2]==target[2])return true;

        return false;
    }
};