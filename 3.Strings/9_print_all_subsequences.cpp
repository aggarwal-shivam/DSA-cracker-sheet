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

vector<string> ans;

void print_subsequences(string op, string ip){
    if(ip.length()==0){
        if(op.length()!=0)
            ans.push_back(op);
        return;
    }  
    string op1,op2;
    op1=op+ip[0];
    op2=op;
    ip.erase(ip.begin()+0);
    print_subsequences(op1,ip);
    print_subsequences(op2,ip);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string st="abcd";
    print_subsequences("",st);
    for(auto e : ans){
        cout<<e<<space;
    }
	return 0;
}