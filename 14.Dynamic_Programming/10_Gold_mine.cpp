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

int mine[1001][1001];

int gold_mine(int n, int m){
    int dp[n][m];
    for(int i=0;i<n;i++){
        dp[i][m-1]=mine[i][m-1];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(j>0 && j<m-1){
                int mx=max(dp[j][i+1],dp[j-1][i+1]);
                dp[j][i]=mine[j][i]+max(mx, dp[j+1][i+1]);
            }
            else if(j==0){
                dp[j][i]=mine[j][i]+max(dp[j][i+1], dp[j+1][i+1]);
            }
            else if(j==n-1){
                dp[j][i]=mine[j][i]+max(dp[j][i+1], dp[j-1][i+1]);
            }
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i][0]);
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<dp[i][j]<<space;
    //     }
    //     cout<<endl;
    // }
    return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mine[i][j];
        }
    }
    cout<<gold_mine(n,m)<<endl;
	return 0;
}