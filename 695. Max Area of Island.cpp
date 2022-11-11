//DFS
//O(mn) Time
//O(mn) Space
class Solution {
public:
    int cnt=0;
    int m,n;
    void dfs(int r, int c, vector<vector<int>>& grid){
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]!=1)return;

        vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
        grid[r][c]=-1;
        cnt++;
        for(auto dir:dirs){
            int rr=r+dir.first;
            int cc=c+dir.second;

            dfs(rr,cc,grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        m=grid.size();
        n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt=0;
                dfs(i,j,grid);
                res=max(res,cnt);
            }
        }

        return res;
    }
};