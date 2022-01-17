#include <bits/stdc++.h>
using namespace std;

long long Partition(long long a[], long long p, long long r) {
    long long pivot = a[r];
    long long i = p-1;
    for(long long j=p;j<r;j++){
        if(a[j]<=pivot){
            i=i+1;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void QuickSort(long long a[], long long p, long long r) {

if(p<r){
    //Divide
    long long q = Partition(a, p, r);
    
    //Conquer
    QuickSort(a, p, q-1);
    QuickSort(a, q+1, r);
}


}

int main(){
    long long arr[] = { 2, 8, 7, 1, 3, 5, 6, 4};
    long long n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr, 0, n-1);
    
    for(long long i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}