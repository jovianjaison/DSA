//Sliding window + Hashtables
//O(n) Time
//O(26) Space
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> um;
        int n=s.length();
        int maxCurr=0;
        int start=0;

        for(int i=0;i<n;i++){
            maxCurr=max(maxCurr,++um[s[i]]);
            if(i-start+1>maxCurr+k){
                um[s[start]]--;
                start++;
            }
        }

        return n-start;
    }
};