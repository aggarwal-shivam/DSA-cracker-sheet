/*
author : Shivam Aggarwal
Problem link : https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fori(i,a,b) for(i=a; i<b;i++)

int main(){
    ll n,i;
    cin>>n;
    ll a[n];
    fori(i,0,n){
        cin>>a[i];
    }
    ll temp;
    fori(i,0,n/2){
        temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;        
    }
    fori(i,0,n){
        cout<<a[i]<<" ";
    }
}