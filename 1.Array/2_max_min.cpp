/*
author : Shivam Aggarwal
Problem link : https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fori(i,a,b) for(i=a; i<b;i++)
#define vi vector<ll>
#define INF 1e18;

//Simple linear search
pair<ll,ll> method_1(vi a){
    if(a.size()==0){
        return make_pair(-1,-1);
    }
    ll mini=a[0];
    ll maxi=a[0];
    for(auto i=0; i<a.size(); i++){
        if(a[i]>maxi)   maxi=a[i];
        if(a[i]<mini)   mini=a[i];
    }
    return make_pair(mini, maxi);
}

//Tournament method (Using recursion)
pair<ll,ll> method_2(vi a, int start, int end){ //Initially start=0, end=n-1
    if(start < end){
        ll mid=start+(end-start)/2;
        pair<ll,ll> lefty=method_2(a,start,mid);
        pair<ll,ll> righty=method_2(a,mid+1,end);
        pair<ll,ll> ans;
        ans.first=min(lefty.first, righty.first);
        ans.second=max(lefty.second, righty.second);
        return ans;
    }
    else if(start==end){
        return make_pair(a[start], a[start]);
    }
}

pair<ll,ll> method_3(vi a){
    pair<ll,ll> ans;
    ll i;
    if(a.size()%2==0){
        if(a[0]>a[1]){
            ans.first=a[1];
            ans.second=a[0];
        }
        else{
            ans.first=a[0];
            ans.second=a[1];
        }
        i=2;
    }
    else{
        ans.first=a[0];
        ans.second=a[0];
        i=1;
    }
    while(i<a.size()){
        if(a[i]>a[i+1]){
            if(a[i]>ans.second) ans.second=a[i];
            if(a[i+1]<ans.first)    ans.first=a[i+1];
        }
        else{
            if(a[i+1]>ans.second)   ans.second=a[i+1];
            if(a[i]<ans.first)  ans.first=a[i];
        }
        i+=2;
    }
    return ans;
}

int main(){
    ll n,i;
    cin>>n;
    vi a(n);
    fori(i,0,n) cin>>a[i];
    pair<ll,ll> ans;
    ans=method_1(a);
    cout<<"Answer using Simple method:\n";
    cout<<ans.first<<"     "<<ans.second<<endl;
    ans=method_2(a,0,n-1);
    cout<<"Answer using tournament method:\n";
    cout<<ans.first<<"     "<<ans.second<<endl;
    ans=method_3(a);
    cout<<"Answer using pairwise comparison:\n";
    cout<<ans.first<<"     "<<ans.second<<endl;
    return 0;
}