/*
author: Shivam Aggarwal
problem link: https://www.geeksforgeeks.org/space-optimized-solution-lcs/
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

int space_optimized_lcs(string X, string Y, int n, int m){
    int dp[2][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        int index=i%2;
        int prev=1-index;
        for(int j=1;j<=m;j++){ 
            if(X[i-1]==Y[j-1]){
                dp[index][j]=1+dp[prev][j-1];
            }
            else 
                dp[index][j]=max(dp[index][j-1],dp[prev][j]);
        }
    }
    int index=n%2;
    return dp[index][m];
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string x,y;
    cin>>x>>y;
    int n,m;
    n=x.length();
    m=y.length();
    cout<<space_optimized_lcs(x,y,n,m)<<endl;
	return 0;
}