//Quick Select in a hurry 1
//O(n) Avg O(n^2) Worst Time
//O(1) Space
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(),nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};

//Quick Select in a hurry 2
//O(n + k*log k + k*(log k)*(log nk)) Avg O(nlogk) Worst Time
//O(1) Space
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
        return nums[k - 1];
    }
};

//Quick Select
//O(n) Avg O(n^2) Worst Time
//O(1) Space
class Solution {
public:
    int partition(int l, int r, vector<int>& nums, int pivot){
        int id=l;
        swap(nums[pivot],nums[r]);
        for(int i=l;i<r;i++){
            if(nums[i]<nums[r]){
                swap(nums[id],nums[i]);
                id++;
            }
        }
        swap(nums[id],nums[r]);
        return id;
    }

    int quickselect(int l, int r, vector<int>& nums, int kth_smallest){
        if(l==r)return nums[l];

        //Generates random seed
        srand(time(0));
        int id = l+(rand()%(r-l));
        id=partition(l,r,nums,id);

        if(id==kth_smallest)return nums[id];
        else if(id<kth_smallest){
            return quickselect(id+1,r,nums,kth_smallest);
        }else{
            return quickselect(l,id-1,nums,kth_smallest);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        return quickselect(0,n-1,nums, n-k);
    }
};

//Min Heap
//O(nlogk) Time
//O(k) Space
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==0)return -1;
        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i:nums){
            pq.push(i);
            if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};