#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) {
long long min = a[0], max = a[0];
 for(int i=1;i<n;i++){
     if(a[i]<min){
         min = a[i];
     }
     if(a[i]>max){
         max = a[i];
     }
 }
 return make_pair(min,max);
}

int main(){
    pair<long long, long long> p;
    long long arr[] = { 10, 40, 50, 30, 70};
    p = getMinMax(arr, 5);
    cout<<"Min:"<<p.first<<" Max:"<<p.second<<"\n";
}