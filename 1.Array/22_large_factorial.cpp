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

int res[100000];
int size=1;

void multiply(int x, int res[], int* size){
    int prod=1;
    int carry=0;
    for(int i=0;i<*size;i++){
        prod=x*res[i]+carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    while(carry!=0){
        int d=carry%10;
        res[*size]=d;
        *size=*size+1;
        carry=carry/10;
    }
}

void large_factorial(int n){
    res[0]=1;
    for(int x=1;x<=n;x++){
        multiply(x,res,&size);
    }
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int num=10;
    large_factorial(num);
    for(int i=size-1;i>=0;i--){
        cout<<res[i];
    }
	return 0;
}