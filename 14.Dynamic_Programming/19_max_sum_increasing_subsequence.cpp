/*
author : Shivam Aggarwal
problem link : https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
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

int MSIS_recursive(int a[], int i, int n, int prev, int sum){
    if(i==n)    return sum;
    int excl=MSIS_recursive(a,i+1,n,prev,sum);

    int incl=sum;
    if(a[i]>prev){
        incl=MSIS_recursive(a,i+1,n,a[i],sum+a[i]);
    }
    return max(incl, excl);
}

int MSIS_bottom_up(int a[], int n){
    int sum[n]={0};
    sum[0]=a[0];
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(sum[i]<sum[j] && a[j]<a[i])
                sum[i]=sum[j];
        }
        sum[i]+=a[i];
    }
    int ans=-1;
    for(auto e : sum){
        ans=max(ans,e);
    }
    return ans;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    fori(i,0,n) cin>>a[i];
    cout<<MSIS_recursive(a,0,n,-1,0)<<endl;
    cout<<MSIS_bottom_up(a,n)<<endl;
	return 0;
}