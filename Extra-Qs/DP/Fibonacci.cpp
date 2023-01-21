//Bottom-up DP
//O(n) Time
//O(1) Space
class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;

        int a=0;
        int b=1;
        int c;

        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }

        return c;
    }
};

//Bottom-up DP
//O(n) Time
//O(n) Space
class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;

        vector<int> vec(n+1,-1);
        vec[0]=0;
        vec[1]=1;

        for(int i=2;i<=n;i++){
            vec[i]=vec[i-2]+vec[i-1];
        }

        return vec[n];
    }
};

//Top-Down DP with memoization
//O(n) Time
//O(n) Space
class Solution {
public:
    vector<int> dp;

    int recFib(int n){
        cout<<"reached "<<n<<"\n";
        if(n<=1)return n;
        
        if(dp[n]==-1)
            dp[n] = recFib(n-2) + recFib(n-1);

        return dp[n];
    }

    int fib(int n) {
        if(n<=1)return n;
        
        dp.resize(n+1,-1);
        dp[0]=0;
        dp[1]=1;

        return recFib(n);
    }   
};

//Top-Down DP
//O(2^n) Time
//O(n) Space
class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;

        return fib(n-2)+fib(n-1);
    }
};