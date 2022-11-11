//Binary Search
//O(log(mn)) Time
//O(1) Space
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        int low=0;
        int high=(m*n)-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int r=floor(mid/n);
            int c=mid%n;
            if(matrix[r][c]==target)return true;
            if(matrix[r][c]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return false;
    }
};