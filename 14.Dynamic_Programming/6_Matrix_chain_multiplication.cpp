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

int MCM(int dims[], int i, int j){
    if(dp[i][j]!=-1)    return dp[i][j];
    if(i>=j)    return 0;
    int ans=inf;
    for(int k=i;k<=j-1;k++){
        ans=min(ans,MCM(dims,i,k)+MCM(dims,k+1,j)+dims[i-1]*dims[k]*dims[j]);
    }
    dp[i][j]=ans;
    return dp[i][j];
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    int p[]={10, 20, 30, 40, 30};
    int i=1, j=4;
    cout<<MCM(p,i,j)<<endl;
	return 0;
}