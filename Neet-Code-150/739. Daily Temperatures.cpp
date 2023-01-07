//Stack - Forward traversal
//O(n) Time
//O(n) Space
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> res(temperatures.size(),0);

        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int x=st.top();st.pop();
                res[x]=i-x;
            }
            st.push(i); 
        }

        return res;
    }
};