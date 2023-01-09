//DFS
//O(mn) Time
//O(mn) Space
class Solution {
public:
    int N,M;
    vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& Ocean){
        if(Ocean[r][c])return;
        
        Ocean[r][c]=true;
        for(auto d:dirs){
            int x=r+d.first;
            int y=c+d.second;
            
        if(x>=0 && y>=0 && x<N && y<M && !Ocean[x][y] && heights[x][y]>=heights[r][c]){
                dfs(x,y,heights,Ocean);
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        N=heights.size();
        M=heights[0].size();
        
        vector<vector<bool>> Pacific(N,vector<bool>(M,false));
        vector<vector<bool>> Atlantic(N,vector<bool>(M,false));
        vector<vector<int>> res;
        
        for(int j=0;j<M;j++)
            dfs(0,j,heights,Pacific);
        
        for(int i=1;i<N;i++)
            dfs(i,0,heights,Pacific);
        
        for(int j=0;j<M;j++)
            dfs(N-1,j,heights,Atlantic);
        
        for(int i=0;i<N-1;i++)
            dfs(i,M-1,heights,Atlantic);
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(Pacific[i][j] && Atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        
        return res;
    }
};