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

string longest_palindrome(string s){
    int n=s.length();
    int longest=-1;
    int i,j;
    string ans;
    string temp,rev;
    int flag=0;
    for(i=0;i<n;i++){
        for(j=n-1;j>=i;j--){
            temp=s.substr(i,j-i+1);
            rev=string(temp.rbegin(),temp.rend());
            bool x=(temp==rev);
            if(x){
                
                if(j-i+1>longest){
                    flag=1;
                    longest=j-i+1;
                    ans=temp;
                }   
            }
        }
    }
    return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    w(T){
        string s;
        cin>>s;
        cout<<longest_palindrome(s)<<endl;
    }
	return 0;
}