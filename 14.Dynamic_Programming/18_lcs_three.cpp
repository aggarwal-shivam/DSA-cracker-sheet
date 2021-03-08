/*
author: Shivam Aggarwal
problem link: https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1
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

int dp[101][101][101];

// int solve(string x, string y, string z, int a, int b, int c){
//     if(a==-1 || b==-1 || c==-1) return 0;
//     if(dp[a][b][c]!=-1) return dp[a][b][c];
//     if(x[a]==y[b] && y[b]==z[c]){
//         dp[a][b][c]=1+solve(x,y,z,a-1,b-1,c-1);
//     }
//     else{
//         int mx=max(solve(x,y,z,a-1,b,c), solve(x,y,z,a,b-1,c));
//         dp[a][b][c]=max(mx,solve(x,y,z,a,b,c-1));
//     }
//     return dp[a][b][c];
// }

// int lcs_of3(string X, string Y, string Z, int a, int b, int c){
//     memset(dp,-1,sizeof(dp));
//     int ans=solve(X,Y,Z,a-1,b-1,c-1);
//     return ans;
// }

int lcs_of3(string x, string y, string z, int a, int b, int c){
    int dp[a+1][b+1][c+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                if(x[i-1]==y[j-1] && y[j-1]==z[k-1])
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                else{
                    int mx=max(dp[i-1][j][k], dp[i][j-1][k]);
                    dp[i][j][k]=max(mx,dp[i][j][k-1]);
                } 
                    
            }
        }
    }
    return dp[a][b][c];
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a,b,c;
    cin>>a>>b>>c;
    int n,m,p;
    n=a.length();
    m=b.length();
    p=c.length();
    cout<<lcs_of3(a,b,c,n,m,p)<<endl;
	return 0;
}