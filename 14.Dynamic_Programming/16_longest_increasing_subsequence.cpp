/*
author: Shivam Aggarwal
problem link: https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
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

int longest_increasing_subsequence(int n, int arr[]){   //Time taken is O(n^2)
    int lis[n];
    fori(i,0,n) lis[i]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && lis[i]<lis[j]+1){
                lis[i]=1+lis[j];
            }
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        ans=max(ans,lis[i]);
    }
    return ans;
}

int longest_increasing_subsequence_optimized(int n, int arr[]){   
    //will take O(n logn) time using the binary search to find the immediate next of an element
    vector<int> seq;
    seq.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>seq.back()){
            seq.push_back(arr[i]);
        }
        else{
            int index=lower_bound(seq.begin(), seq.end(), arr[i])-seq.begin();
            seq[index]=arr[i];
        }
    }
    return seq.size();
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
    cin>>n;
    int arr[n];
    fori(i,0,n) cin>>arr[i];
    cout<<longest_increasing_subsequence_optimized(n,arr)<<endl;
    return 0;
}