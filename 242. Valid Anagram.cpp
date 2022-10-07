//Hashmap
//O(n) Time
//O(1) Space, as hashtable size is always constant ie. 26
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char,int> um;
        for(int i=0;i<s.length();i++){
            um[s[i]]++;
            um[t[i]]--;
        }

        for(auto item:um){
            if(item.second!=0)return false;
        }
        return true;
    }
};

//Sorting
//O(nlogn) Time
//O(1) Space
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return s==t;
    }
};