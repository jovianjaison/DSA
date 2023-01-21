//Two pointer
//O(n) Time
//O(1) Space
class Solution {
public:
    bool isPalindrome(string s) {
        int p1=0;
        int p2=s.length();

        while(p1<p2){
            if(isalnum(s[p1]) && isalnum(s[p2])){
                if(tolower(s[p1])!=tolower(s[p2])){
                    return false;
                }else{
                    p1++;
                    p2--;
                }
            }else {
                if(!isalnum(s[p1])){
                    p1++;
                }
                if(!isalnum(s[p2])){
                    p2--;
                }
            }
        }

        return true;
    }
};