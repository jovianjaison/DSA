#include <bits/stdc++.h>
using namespace std;

void reverseString(string& s, int cur) {
    if(cur==s.length()/2)
        return;

    reverseString(s, cur+1);
    swap(s[cur], s[s.size()-1-cur]);
    return;
}

int main(){
    string str = "Hello World!";
    reverseString(str, 0);
    cout<<str<<"\n";
}