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

bool subset_sum(int S[], int n, int target){
    bool dp[n+1][target+1];
    for(int i=0;i<=n;i++)   dp[i][0]=true;
    for(int i=1;i<=target;i++)  dp[0][i]=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(S[i-1]<=j){
                dp[i][j]=dp[i-1][j-S[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

int solve(int N, int arr[]){
    int sumy=0;
    for(int i=0;i<N;i++)    sumy+=arr[i];
    if(sumy%2==1)   return 0;
    else{
        sumy/=2;
        if(subset_sum(arr,N,sumy))  return 1;
        return 0;
    }
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    fori(i,0,n) cin>>a[i];
    cout<<solve(n,a)<<endl;
	return 0;
}