//DP
//O(n^2) Time
//O(1) Space
class Solution {
public:
    int countPalLength(string s, int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }

    string longestPalindrome(string s) {
        if(s.length()==0)return "";
        int res=INT_MIN;
        int start=0;
        int end=0;
        for(int i=0;i<s.length();i++){
            int c1=countPalLength(s,i,i);
            int c2=countPalLength(s,i,i+1);
            int c = max(c1,c2);
            if(c>res){
                start=i-((c-1)/2);
                res=c;
            }
        }

        cout<<start<<" "<<end<<"\n";
        return s.substr(start,res);
    }
};