#include <bits/stdc++.h>
using namespace std;

void reOrder(long long *a, int n) {
    long long l = 0, r = n-1;
     while(l<=r){
        if(a[l]>=0 && a[r]<0){
            swap(a[l],a[r]);
            l++;
            r--;
        }
        if(a[r]>=0){
            r--;
        }
        if(a[l]<0){
            l++;
        }
     }
     
     for(int i=0;i<n;i++){
         cout<<arr[i]<<" ";
     }
     cout<<"\n";
}

int main(){
    long long arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6};
    long long n = sizeof(arr)/sizeof(arr[0]);
    reOrder(arr, n);
    return 0;
}