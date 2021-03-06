/*
author: Shivam Aggarwal
problem link: https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
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

// int dp[10001];

int max_cut_segments(int n, int x, int y, int z){
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<=n;i++){
        if(dp[i]!=-1){
            if(i+x<=n)
                dp[i+x]=max(dp[i]+1,dp[i+x]);
            if(i+y<=n)
                dp[i+y]=max(dp[i]+1,dp[i+y]);
            if(i+z<=n)
                dp[i+z]=max(dp[i]+1,dp[i+z]);
        }
    }
    if(dp[n]==-1)   dp[n]=0;    
    return dp[n];
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout<<max_cut_segments(68,11,49,70)<<endl;
	return 0;
}