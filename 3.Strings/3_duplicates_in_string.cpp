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

vector<char> method1(string s){      //using a count array of size 26
    vector<int> ans(26,0);
    vector<char> duplicates;
    for(auto e:s){
        ans[e-'a']++;
    }
    for(int i=0;i<26;i++){
        if(ans[i]>1){
            duplicates.push_back(i+'a');
        }
    }
    return duplicates;
}

vector<char> method2(string s){         //using sorting
    sort(s.begin(), s.end());
    vector<char> ans;
    ans.push_back(s[0]);
    for(int i=1;i<s.length();i++){
        if(s[i]!=s[i-1])    ans.push_back(s[i]);
    }
    return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    s="babababacc";
    vector<char> dups=method2(s);
    for(auto e: dups)  cout<<e<<space;
	return 0;
}