//Union Find
//O(E + α(n)) Time (E=number of edges, V=number of vertices : For every edge, combine is called. α(n) is the inverse Ackermann function.)
//O(V) Space
class Solution {
public:
    vector<int> disjointSet,rank;
    int find(int v){
        if(v==disjointSet[v])return v;

        return disjointSet[v] = find(disjointSet[v]);
    } 
    int combine(int v1, int v2){
        v1 = find(v1);
        v2 = find(v2);

        if(v1==v2)return 0;
        else{
            if(rank[v1]>=rank[v2]){
                disjointSet[v2]=v1;
                rank[v1]++;
            }else{
                disjointSet[v1]=v2;
                rank[v2]++;
            }
        }

        return 1;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        disjointSet.resize(n);
        rank.resize(n);

        int res=n;

        for(int i=0;i<n;i++)
            disjointSet[i]=i;
        
        for(int i=0;i<edges.size();i++){
            res-=combine(edges[i][0],edges[i][1]);
        }

        return res;
    }
};

//DFS
//O(E+V) Time (E=number of edges, V=number of vertices)
//O(E+V) Space
class Solution {
public:
    vector<bool> vis;
    int res=0;

    void dfs(int id, vector<vector<int>>& adj){
        vis[id]=true;
        for(int i=0;i<adj[id].size();i++){
            if(!vis[adj[id][i]]){
                dfs(adj[id][i],adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vis.resize(n,false);

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(i,adj);
                res++;
            }
        }
        
        return res;
    }
};