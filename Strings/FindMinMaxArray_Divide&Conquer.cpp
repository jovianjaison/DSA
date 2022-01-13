#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> getMinMax(long long a[], int low, int high) {
    int min,max;
    
    //cout<<"l:"<<low<<" h:"<<high<<"\n";
    
    if(low==high)
        return make_pair(a[low],a[high]);

    if(high == low + 1){
        if(a[low]>a[high]){
            max = a[low];
            min = a[high];
        }else{
            max = a[high];
            min = a[low];
        }
        return make_pair(min,max);
    }

    int mid = (high + low)/2;
    pair<long long,long long> pl = getMinMax(a,low,mid);
    pair<long long, long long> pr = getMinMax(a,mid+1,high);

    if(pl.first<pr.first){
        min = pl.first;
    }else{
        min = pr.first;
    }

    if(pl.second>pr.second){
        max = pl.second;
    }else{
        max = pr.second;
    }

    return make_pair(min,max);
}

int main(){
    pair<long long, long long> p;
    long long arr[] = { 10, 40, 50, 30, 70};
    p = getMinMax(arr, 0, 4);
    cout<<"Min:"<<p.first<<" Max:"<<p.second<<"\n";
}