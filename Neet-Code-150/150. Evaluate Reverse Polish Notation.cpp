//Stack
//O(n) Time
//O(n) Space
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
                st.push(stoi(tokens[i]));
            }else{
                long long n1=st.top();st.pop();
                long long n2=st.top();st.pop(); 
                if(tokens[i]=="+")
                    st.push(n2+n1);
                else if(tokens[i]=="-")
                    st.push(n2-n1);
                else if(tokens[i]=="/")
                    st.push(floor(n2/n1));
                else if(tokens[i]=="*")
                    st.push(n2*n1);
            }
        }

        return st.top();
    }
};