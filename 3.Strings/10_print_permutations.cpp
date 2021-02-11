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

void method1(string s, int fixed){ //using recursion and no duplicates
    if(fixed==s.length()){
        cout<<s<<space;
        return;
    }
    string temp;
    for(int i=fixed;i<s.length();i++){
        // temp=s.copy();
        temp=s;
        swap(temp[fixed],temp[i]);
        method1(temp,fixed+1);
    }
}

void method2(string s, int l, int r){   //Using backtracking and no duplicates.
    if(l==r){
        cout<<s<<space;
        return;
    }
    for(int i=l;i<=r;i++){
        swap(s[l],s[i]);
        method2(s,l+1,r);
        swap(s[l],s[i]);    //backtracking
    }
}

void method3(string s){         //Using STL next_permute
    //Idea is to keep printing permmutations till we get the largest string lexicographically
    sort(s.begin(),s.end());
    do{
        cout<<s<<space;
    }while(next_permutation(s.begin(),s.end()));
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s="abc";
    cout<<"Using method 1 :\n";
    method1(s,0);
    cout<<endl;
    cout<<"Using method 2 :\n";
    method2(s,0,s.length()-1);
    cout<<endl;
    cout<<"Using method 3 :\n";
    method3(s);
	return 0;
}