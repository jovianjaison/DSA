#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
    {
        int c0 = 0,c1 = 0,c2 = 0;
        
        for(int i=0;i<n;i++){
            if(a[i]==0){
                c0++;
            }else if(a[i]==1){
                c1++;
            }else{
                c2++;
            }
                
        }
        
        for(int i=0;i<c0;i++){
            a[i] = 0;
        }
        for(int i=c0;i<c0+c1;i++){
            a[i] = 1;
        }
        for(int i=c0+c1;i<c0+c1+c2;i++){
            a[i] = 2;
        }
    }

int main(){
    int arr[] = {0, 2, 1, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    return 0;
}