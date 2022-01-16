#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
        sort(arr,arr+r);
        return arr[k-1];
}

int findKthLargest(int arr[], int l, int r, int k) {
        sort(arr,arr+r);
        return arr[r-k];
}

int main(){
    int arr[] = { 10, 40, 50, 30, 70};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Kth smallest:"<<kthSmallest(arr, 0, n, 2)<<"\n";
    cout<<"Kth largest:"<<findKthLargest(arr, 0, n, 2)<<"\n";
    return 0;
}