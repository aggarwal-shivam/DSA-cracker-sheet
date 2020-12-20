/*
author : Shivam Aggarwal
Problem link : https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fori(i,a,b) for(i=a; i<b;i++)
#define vi vector<ll>
#define INF 1e18
#define min_heap priority_queue<long long, vector<long long>, greater<long long> >

ll kth_smallest(min_heap a, ll k){
    k--;
    while(k--)  a.pop();
    return a.top();    
}

int main(){
    ll n,k,i;
    cin>>n>>k;
    assert(k<n);
    // vi a(n);
    min_heap a;
    ll item;
    while(n--){
        cin>>item;
        a.push(item);
    }
    cout<<"kth smallest item is : "<<kth_smallest(a,k)<<endl;
    return 0;
}