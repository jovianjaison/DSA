#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> getMinMax(long long a[], int n) {
 return make_pair(*min_element(a, a+n),*max_element(a, a+n));
}

int main(){
    pair<long long, long long> p;
    long long arr[] = { 10, 40, 50, 30, 70};
    p = getMinMax(arr, 5);
    cout<<"Min:"<<p.first<<" Max:"<<p.second<<"\n";
}