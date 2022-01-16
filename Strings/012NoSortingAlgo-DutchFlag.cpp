#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
    {
        int l = 0, m = 0, h = n -1;
        
        for(int i=0;i<n,m<=h;i++){
            if(a[i]==0){
                swap(a[l],a[i]);
                l++;
                m++;
            }else if(a[i]==1){
                m++;
            }else{
                swap(a[i],a[h]);
                h--;
                i--;
            }
                
        }
    }

int main(){
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}