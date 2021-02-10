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

string countAndSay(int n) {
        vector<string> dp;
        dp.resize(n);
        dp.clear();
        string current;
        string tempo="1";
        dp.push_back(tempo);
        int count;
        char temp;
        for(int q=1;q<n;q++){
            cout<<"here\n";
            string s=dp[q-1];
            count=1;
            current="";
            temp=s[0];
            for(int i=1;i<s.length();i++){
                if(s[i]==s[i-1])    count++;
                else{
                    current+=to_string(count);
                    current+=temp;
                    count=1;
                    temp=s[i];
                }
            }
            current+=to_string(count);
            current+=temp;
            dp.push_back(current);
        }
        return dp[n-1];
    }

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n=2;
    cout<<countAndSay(5);
	return 0;
}