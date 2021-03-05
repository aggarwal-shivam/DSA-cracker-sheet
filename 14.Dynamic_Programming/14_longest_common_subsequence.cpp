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



int lcs_recursive(string X, string Y, int n, int m){
    //base condition
    if(n==0 || m==0)    return 0;
    //choice diagram implementation
    if(X[n-1]==Y[m-1])
        return 1+lcs_recursive(X,Y,n-1,m-1);
    else
        return max(lcs_recursive(X,Y,n-1,m),    lcs_recursive(X,Y,n,m-1));
}

int dp[1000][1000];

int lcs_memoized(string X, string Y, int n, int m){
    if(dp[n][m]!=-1)    return dp[n][m];
    if(X[n-1]==Y[m-1]){
        dp[n][m]=1+lcs_memoized(X,Y,n-1,m-1);
        return dp[n][m];
    }
    else{
        dp[n][m]=max(lcs_memoized(X,Y,n-1,m),   lcs_memoized(X,Y,n,m-1));
        return dp[n][m];
    }
}

int lcs_top_down(string X, string Y, int n, int m){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(X[i-1]==Y[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string X,Y;
    X="abcdef";
    Y="adefgh";
    int n=6, m=6;
    cout<<X<<space<<Y<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else 
                dp[i][j]=-1;
        }
    }
    cout<<"recursive: "<<lcs_recursive(X,Y,n,m)<<endl;
    cout<<"memoized: "<<lcs_memoized(X,Y,n,m)<<endl;
    cout<<"TOP-DOWN: "<<lcs_top_down(X,Y,n,m)<<endl;
	return 0;
}