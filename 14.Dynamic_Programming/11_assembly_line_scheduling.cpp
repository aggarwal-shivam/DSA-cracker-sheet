/*
author: Shivam Aggarwal
problem link: https://www.geeksforgeeks.org/assembly-line-scheduling-dp-34/
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

int a[2][1001];
int t[2][1001];

int assembly(int n,int e[],int x[]){
    //n is the number of stations at each line
    //e is the arr of size 2 denoting entry load at both lines
    //x is the arr of size 2 denoting exit load at both lines
    int dp[2][n+1];
    dp[0][n]=a[0][n-1]+x[0];
    dp[1][n]=a[1][n-1]+x[1];
    for(int i=n-1;i>0;i--){
        dp[0][i]=a[0][i-1]+min(dp[0][i+1], dp[1][i+1]+t[0][i]);
        dp[1][i]=a[1][i-1]+min(dp[1][i+1], dp[0][i+1]+t[1][i]);
    }
    dp[0][0]=dp[0][1]+e[0];
    dp[1][0]=dp[1][1]+e[1];
    return min(dp[0][0], dp[1][0]);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, e[2], x[2];
    cin>>n;
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>t[i][j];
        }
    }
    cin>>e[0]>>e[1];
    cin>>x[0]>>x[1];
    cout<<assembly(n,e,x)<<endl;
	return 0;
}