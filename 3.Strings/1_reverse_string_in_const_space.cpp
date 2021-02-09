#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
        for(int i=0; i<s.size()/2; i++){
            swap(s[i],s[s.size()-i-1]);
        }
    }

int main(){
    return 0;
}