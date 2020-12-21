/*
author : Shivam Aggarwal
Problem link : https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fori(i,a,b) for(i=a; i<b;i++)
#define vi vector<ll>
#define INF 1e18
#define min_heap priority_queue<long long, vector<long long>, greater<long long> >

void rearrange(int a[], int n){
    int low,high;
    low=0;
    high=n-1;
    while(low<=high){
        if(a[low]<0){
            low++;
            continue;
        }
        if(a[low]>0){
            swap(a[low], a[high--]);
            continue;
        }
    }
}

int main(){
    int n,i;
    cin>>n;
    int a[n];
    fori(i,0,n) cin>>a[i];
    rearrange(a,n);
    fori(i,0,n) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}