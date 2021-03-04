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

int dp[1001][1001];

int solve(int n, int r){
    if(dp[n][r]!=-1)    return dp[n][r];
    if(r>n){
        return 0;
    } 
    if(r==0 || r==n){
        dp[n][r]=1;
        return 1;
    }    
    dp[n][r]=(solve(n-1,r-1)%1000000007+solve(n-1,r)%1000000007)%1000000007;
    return dp[n][r];
}

int nCr(int n, int r){
    memset(dp,-1,sizeof(dp));
    int ans=solve(n,r);
    return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,r;
    cin>>n>>r;
    // memset(dp,-1,sizeof(dp));
    cout<<nCr(n,r)<<endl;
	return 0;
}