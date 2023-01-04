//Min-Heap
//O(n log(n) + m log(k)) Time (where n is length of init input, m is num of calls to add)
//O(n) Space
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i:nums){
            pq.push(i);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K)
            pq.pop();
        
        return pq.top();
    }
};