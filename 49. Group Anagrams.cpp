//2 Hashtables - Encoding
//O(nk) Time (n=number of strings, k=length of longest string)
//O(nk) Space
class Solution {
public:
    string encode(string str){
        string res="";
        unordered_map<char,int> um;
        
        for(char c:str){
            um[c]++;
        }

        for(int i=0;i<26;i++){
            if(um.find('a'+i)!=um.end()){
                res+=to_string(um['a'+i]);
                res+="#";
            }else{
                res+="0#";
            }
        }
        
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;

        for(string str:strs){
            string temp=str;
            str=encode(str);
            if(um.find(str)!=um.end()){
                um[str].push_back(temp);
            }else{
                um[str]={temp};
            }
        }

        vector<vector<string>> res;
        for(auto list:um){
            res.push_back(list.second);
        }

        return res;
    }
};

//Hashtable - Sorting
//O(nklogk) Time
//O(nk) Space
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;

        for(string str:strs){
            string temp=str;
            sort(str.begin(),str.end());
            if(um.find(str)!=um.end()){
                um[str].push_back(temp);
            }else{
                um[str]={temp};
            }
        }

        vector<vector<string>> res;
        for(auto list:um){
            res.push_back(list.second);
        }

        return res;
    }
};