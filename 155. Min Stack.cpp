//2 Stacks Optimized
//O(1) Time
//O(n) Space (n=number of operations, less duplicates of min val)
class MinStack {
public:
    stack<int> st1;
    stack<pair<int,int>> st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty() || st2.top().first>val){
            st2.push({val,1});
        }else if(st2.top().first==val){
            st2.top().second++;
        }
    }
    
    void pop() {
        int x=st1.top();st1.pop();
        if(x==st2.top().first){
            st2.top().second--;
            if(st2.top().second==0)
                st2.pop();
        }
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top().first;
    }
};

//2 Stacks
//O(1) Time
//O(n) Space (n=number of operations, less duplicates of min val)
class MinStack {
public:
    stack<int> st1,st2;
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty() || st2.top()>=val){
            st2.push(val);
        }
    }
    
    void pop() {
        int x=st1.top();st1.pop();
        if(x==st2.top())
            st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};

//Stack of pair
//O(1) Time
//O(n) Space (n=number of operations)
class MinStack {
public:
    stack<pair<int,int>> st;
    int currMin=INT_MAX;
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty())currMin=val;
        else currMin=min(getMin(),val);
        st.push({val,currMin});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};