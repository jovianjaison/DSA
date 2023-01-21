//Bellman Ford
//O((N+E) * K) Time 
//O(N) Space
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> minDist(n,1e5);
        minDist[src]=0;

        for(int j=0;j<=k;j++){
            vector<int> temp(minDist);
            for(int i=0;i<flights.size();i++){
                if(flights[i][2]+minDist[flights[i][0]]<temp[flights[i][1]])
                    temp[flights[i][1]]=flights[i][2]+minDist[flights[i][0]];
            }
            minDist=temp;
        }

        return minDist[dst]==1e5?-1:minDist[dst];
    }
};

//Dijkstra variation/ Same as BFS but using Priority queue
//O(N + E*K*log(E*K)) Time
//O(N + E*K) Space
class Solution {
public:
    vector<vector<pair<int,int>>> adjList;
    vector<int> nodeMin;
    int currCount=-1;

    void bfs(int src, int dst, int k){
        priority_queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,currCount}});

        while(!q.empty()){
            int currNode = q.top().second.first;
            int currVal = q.top().first;
            int currPath = q.top().second.second;

            q.pop();

            if(currPath==k){
                continue;
            }

            for(auto neighbour:adjList[currNode]){
                if(nodeMin[neighbour.first]>currVal+neighbour.second){
                    nodeMin[neighbour.first]=currVal+neighbour.second;
                    q.push({nodeMin[neighbour.first],{neighbour.first,currPath+1}});
                }
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adjList.resize(n);
        nodeMin.resize(n,INT_MAX);
        for(auto flight:flights){
            adjList[flight[0]].push_back({flight[1],flight[2]});
        }

        bfs(src,dst,k);

        return nodeMin[dst]==INT_MAX?-1:nodeMin[dst];
    }
};

//BFS
//O(N + E*K) Time
//O(N + E*K) Space
class Solution {
public:
    vector<vector<pair<int,int>>> adjList;
    vector<int> nodeMin;
    int currCount=-1;

    void bfs(int src, int dst, int k){
        queue<pair<int,pair<int,int>>> q;
        q.push({src,{0,currCount}});

        while(!q.empty()){
            int currNode = q.front().first;
            int currVal = q.front().second.first;
            int currPath = q.front().second.second;

            q.pop();

            if(currPath==k){
                continue;
            }

            for(auto neighbour:adjList[currNode]){
                if(nodeMin[neighbour.first]>currVal+neighbour.second){
                    nodeMin[neighbour.first]=currVal+neighbour.second;
                    q.push({neighbour.first,{nodeMin[neighbour.first],currPath+1}});
                }
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adjList.resize(n);
        nodeMin.resize(n,INT_MAX);
        for(auto flight:flights){
            adjList[flight[0]].push_back({flight[1],flight[2]});
        }

        bfs(src,dst,k);

        return nodeMin[dst]==INT_MAX?-1:nodeMin[dst];
    }
};