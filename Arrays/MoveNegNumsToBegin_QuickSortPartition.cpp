#include <bits/stdc++.h>
using namespace std;

void reOrder(long long a[], long long p, long long r) {
    long long pivot = a[r];
    long long i = p-1;
    for(long long j=p;j<r;j++){
        if(a[j]<0){
            i=i+1;
            swap(a[i],a[j]);
        }
    }
}

int main(){
    long long arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6};
    long long n = sizeof(arr)/sizeof(arr[0]);
    reOrder(arr, 0, n);


    for(long long i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}