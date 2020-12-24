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

int max_subarray_sum(int a[], int n){
    int start=0,end=0;
    int current_max=a[0];
    int global_max=a[0];
    for(int i=1;i<n;i++){
        if(current_max+a[i] > a[i]){
            current_max+=a[i];
            if(current_max>global_max)  global_max=current_max;
            end=i;
        }
        else if(a[i] >= current_max+a[i]){
            current_max=a[i];
            if(current_max > global_max)    global_max=current_max;
            start=i;
            end=i;
        }
    }
    return global_max;
}


int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    fori(i,0,n) cin>>a[i];
    cout<<max_subarray_sum(a,n)<<endl;
	return 0;
}