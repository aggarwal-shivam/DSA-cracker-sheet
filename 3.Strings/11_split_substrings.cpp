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

int split_into_subs(string str){
    int n=str.length();
    int count=0, zero=0, one=0;
    fori(i,0,n){
        if(str[i]=='1') one++;
        else zero++;
        if(zero==one)   count++;
    }
    if(zero==one)   return count;
    return -1;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    w(T){
        string s;
        cin>>s;
        cout<<split_into_subs(s)<<endl;
    }
	return 0;
}