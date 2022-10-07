//Two pointer
//O(n) Time
//O(1) Space
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int front=0;
        int back=height.size()-1;

        while(front<back){
            int lengthV=back-front;
            int heightV=min(height[front],height[back]);
            if(height[front]>height[back]){
                back--;
            }else{
                front++;
            }
            res=max(res,lengthV*heightV);
        }

        return res;
    }
};

//Brute force
//O(n^2) Time
//O(1) Space
class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;

        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                res=max(res,(j-i)*min(height[i],height[j]));
            }
        }
        return res;
    }
};