//Backtracking
//O(4^n/n) Time
//O(4^n/n) Space
class Solution {
public:
    vector<string> res;
    string curr;
    int N;

    void backtrack(int open_rem, int close_rem){
        if(curr.length()==2*N){
            res.push_back(curr);
            return;
        }
        
        if(open_rem>0){
            curr+="(";
            backtrack(open_rem-1,close_rem);
            curr.pop_back();
        }
        
        if(close_rem>open_rem){
            curr+=")";
            backtrack(open_rem,close_rem-1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        N=n;
        backtrack(n,n);
        return res;
    }
};