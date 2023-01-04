//Randomized QuickSelect
//O(n) Time avg O(n^2) worst
//O(1) Space
class Solution {
public:
    int partition(int L, int R, vector<vector<int>>& P){
        auto euclidean = [](auto &p){return p[0]*p[0] + p[1]*p[1];};
        srand(time(0));
        swap(P[R],P[L+rand()%(R-L+1)]);
        int i=L, pivotDist=euclidean(P[R]);
        for(int j=L;j<=R;j++){
            if(euclidean(P[j])<=pivotDist)
                swap(P[i++],P[j]);
        }

        return i-1;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int L=0;
        int R=points.size()-1;
        int p=points.size();

        while(p!=k){
            p=partition(L,R,points);
            if(p>k)
                R=p-1;
            else
                L=p+1;
        }

        points.resize(k);
        return points;
    }
};

//Min-Heap (Use vector of distances and sort as alt)
//O(nlogk) Time (k=number of nearest points needed)
//O(k) Space
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>> res;
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n;i++){
            double dist=sqrt(pow(points[i][0],2)+pow(points[i][1],2));
            pq.push({dist,i});
            if(pq.size()>k)
                pq.pop();
        }

        while(!pq.empty()){
            int x=pq.top().second;pq.pop();
            res.push_back(points[x]);
        }

        return res;
    }
};

