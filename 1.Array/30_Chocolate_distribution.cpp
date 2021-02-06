/*
author : Shivam Aggarwal
problem link : https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem/0
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int             long long
#define vi              vector<int>	 
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define fori(i,a,b)		for(int i=a; i<b; i++)
#define space			" "
#define enl				"\n"	
#define all(v)			v.begin(),v.end()
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    w(T){
        int n;
        cin>>n;
        vector<int> v(n);
        fori(i,0,n) cin>>v[i];
        int m;
        cin>>m;
        sort(v.begin(),v.end());
        int mini=INT_MAX;
        for(int i=0;i+m-1<n;i++){
            mini=min(mini, v[i+m-1]-v[i]);
        }
        cout<<mini<<enl;
    }
	return 0;
}