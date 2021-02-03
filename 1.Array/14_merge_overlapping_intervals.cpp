#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& a) {
        vector< vector<int> > ans;
        sort(a.begin(),a.end());
        int left,right;
        left=a[0][0];
        right=a[0][1];
        for(int i=0;i<a.size()-1;i++){
            if(a[i+1][0]<=right)  right=max(right,a[i+1][1]);
            else {
                vector<int> tmp(2);
                tmp[0]=left; tmp[1]=right;
                ans.push_back(tmp);
                left=a[i+1][0];
                right=a[i+1][1];
            }
        }
                        vector<int> tmp(2);
                tmp[0]=left; tmp[1]=right;
                ans.push_back(tmp);
        return ans;
        
    }

int main(){
    return 0;
}