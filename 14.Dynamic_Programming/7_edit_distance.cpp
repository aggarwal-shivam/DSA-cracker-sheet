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



int edit_distance(string a, string b){
    int dp[1001][1001];
    int n,m;
    n=a.length();
    m=b.length();
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=m;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=n;i++)   dp[i][0]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int mn=min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j]=1+std::min(mn, dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a,b;
    cin>>a>>b;
    cout<<edit_distance(a,b)<<endl;
    // cout<<a<<space<<b;
	return 0;
}