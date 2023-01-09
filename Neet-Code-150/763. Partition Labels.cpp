//Greedy - OnePass
//O(n) Time
//O(1) Space
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> um;

        for(int i=0;i<s.length();i++){
            char c=s[i];
            um[c]=i;
        }

        vector<int> res;
        int runningMax=INT_MIN;
        int start=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            runningMax=max(runningMax,um[c]);
            if(i==runningMax){
                res.push_back(runningMax-start+1);
                start=i+1;
            }
        }

        return res;
    }
};

//Greedy - Convert to interval problem
//O(n) Time
//O(1) Space
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>> um;
        vector<int> res;

        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c!=s[0] && um[c].first==0)
                um[c].first=i;

            um[c].second=max(um[c].second,i);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto item:um){
            pq.push({item.second.first,item.second.second});
        }

        while(pq.size()>1){
            auto f=pq.top();pq.pop();
            auto s=pq.top();

            if(f.second>s.first){
                pq.pop();
                pq.push({f.first,max(f.second,s.second)});
            }else{
                res.push_back(f.second-f.first+1);
            }
        }

        if(pq.size()==1)
            res.push_back(pq.top().second-pq.top().first+1);
            
        return res;
    }
};