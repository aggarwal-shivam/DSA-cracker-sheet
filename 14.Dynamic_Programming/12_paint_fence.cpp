/*
author: Shivam Aggarwal
problem link: https://www.geeksforgeeks.org/painting-fence-algorithm/
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

int paint_fence(int n, int k){
    int total[n+1];
    int same[n+1], diff[n+1];
    same[1]=0;  diff[1]=k;  total[1]=same[1]+diff[1];
    same[2]=k;  diff[2]=k*(k-1);    total[2]=same[2]+diff[2];
    for(int i=3;i<=n;i++){
        same[i]=diff[i-1];
        diff[i]=total[i-1]*(k-1);
        total[i]=same[i]+diff[i];
    }
    return total[n];
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;
    cin>>n>>k;
    cout<<paint_fence(n,k)<<endl;
	return 0;
}