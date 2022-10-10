//DFS
//O(n) Time
//O(n) Space
class Solution {
public:
int M,N;
    void dfs(int r, int c, vector<vector<char>>& board){
        if(board[r][c]=='R' || board[r][c]=='X')return;

        board[r][c]='R';
        
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        for(auto dir:dirs){
            int rr=r+dir.first;
            int cc=c+dir.second;
            if(rr>=0 && cc>=0 && rr<M && cc<N){
                dfs(rr,cc,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        M=board.size();
        N=board[0].size();

        for(int r=0;r<M;r++){
            dfs(r,0,board);
            dfs(r,N-1,board);
        }

        for(int c=0;c<N;c++){
            dfs(0,c,board);
            dfs(M-1,c,board);
        }

        for(int r=0;r<M;r++){
            for(int c=0;c<N;c++){
                if(board[r][c]=='R')
                    board[r][c]='O';
                else
                    board[r][c]='X';
            }
        }
    }
};