//3 Hashtables, Single pass
//O(N^2) Time (N=9 for sudoku)
//O(N^2) Space
//Technically, as N is fixed, Space and Time can be interpreted as O(1)
class Solution {
public:
bool isValidSudoku(vector<vector<char>>& board) {
        int N=board.size();

        vector<vector<int>> row(N,vector<int>(10,0));
        vector<vector<int>> col(N,vector<int>(10,0));
        vector<vector<int>> grids(N,vector<int>(10,0));

        for(int r=0;r<N;r++){
            for(int c=0;c<N;c++){
                if(board[r][c]=='.')continue;

                if(row[r][board[r][c]-'0']==0)
                    row[r][board[r][c]-'0']++;
                else
                    return false;

                if(col[c][board[r][c]-'0']==0)
                    col[c][board[r][c]-'0']++;
                else
                    return false;
                
                if(grids[(3*floor(r/3))+floor(c/3)][board[r][c]-'0']==0)
                    grids[(3*floor(r/3))+floor(c/3)][board[r][c]-'0']++;
                else
                    return false;
            }
        }

        return true;
    }
};