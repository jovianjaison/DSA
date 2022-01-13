#include <bits/stdc++.h>
using namespace std;

void reverseString(string& s) {
    for(int i=0;i<s.length()/2;i++){
        swap(s[i], s[s.size()-1-i]);
    }
}

int main(){
    string str = "Hello World!";
    reverseString(str);
    cout<<str<<"\n";
}