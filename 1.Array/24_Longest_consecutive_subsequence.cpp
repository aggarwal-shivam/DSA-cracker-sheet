/*
author : Shivam Aggarwal
problem link : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
*/


#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n){
    if(n==1)    return 1;
    sort(arr,arr+n);
    vector<int> elements;
    elements.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1])    elements.push_back(arr[i]);
    }
    int count=1, ans=-1;
    for(int i=1;i<elements.size();i++){
        if(elements[i]==elements[i-1]+1)    count++;
        else    count=1;
        ans=max(count,ans);
    }
    return ans;
}

int main(){
    return 0;
}