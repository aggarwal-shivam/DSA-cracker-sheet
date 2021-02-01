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

void right_rotate(int a[], int start, int end){
    int temp=a[end];
    for(int i=end;i>start;i--){
        a[i]=a[i-1];
    }
    a[start]=temp;
}

void rearrange_alternate(int a[], int n){
    int outofplace=-1;
    for(int index=0;index<n;index++){
        if(outofplace>=0){
            if((a[index]>=0 && a[outofplace]<0) || (a[index]<0 && a[outofplace]>0)){
                right_rotate(a,outofplace,index);

                if(index-outofplace >= 2)   outofplace+=2;
                else    outofplace=-1;
            }
        }
        if(outofplace==-1){
            if((a[index]>=0 && index%2==0) || (a[index]<0 & index%2==1))
                outofplace=index;
        }
    }
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    fori(i,0,n) cin>>a[i];
    rearrange_alternate(a,n);
    fori(i,0,n) cout<<a[i]<<space;
	return 0;
}