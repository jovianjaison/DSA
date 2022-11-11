//DFS
//O(mn) Time
//O(mn) Space (recursion stack)
class Solution {
public:
    int m,n; 
    int res=0;
    vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};
    bool dfs(int r, int c, vector<vector<char>>& grid){
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]!='1')return false;

        grid[r][c]='x';
        for(auto dir:dirs){
            int rr=r+dir.first;
            int cc=c+dir.second;

            dfs(rr,cc,grid);
        }
        return true;
    } 

    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(i,j,grid))res++;
            }
        }

        return res;
    }
};

//Union Find
//O(mn) Time
//O(mn) Space (recursion stack)
class UnionFind{
public:
    UnionFind(vector<vector<char>>& grid){
        count=0;
        int m=grid.size();
        int n=grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    parent.push_back(i*n+j);
                    count++;
                }
                else
                    parent.push_back(-1);
                
                rank.push_back(0);
            }
        }
    }
    int find(int i){
        if(parent[i]!=i)parent[i]=find(parent[i]);
        return parent[i];
    }

    void Union(int x, int y){
        int rootx=find(x);
        int rooty=find(y);

        if(rootx!=rooty){
            if(rank[rootx]>rank[rooty]){
                parent[rooty]=rootx;
            }else if(rank[rooty]>rank[rootx]){
                parent[rootx]=rooty;
            }else{
                parent[rooty]=rootx;
                rank[rootx]++;
            }

            count--;
        }
    }

    int getCount(){
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int m,n; 
    int res=0;
    vector<pair<int,int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};


    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        UnionFind uf(grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';

                    for(auto dir:dirs){
                        int r=i+dir.first;
                        int c=j+dir.second;

                        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]!='1')continue;
                        uf.Union(i*n+j,r*n+c);
                    }
                }
            }
        }

        return uf.getCount();
    }
};