#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector< vector<int> >
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz(a) int(a.size())
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define INF 1e9
int main(){
  ios_base::sync_with_stdio(0);
  ll t;
  cin>>t;
  while(t--){
      ll n,m;
      cin>>n>>m;
      vector<ll> ans,a(n),b(m);
      for(int i=0;i<n;i++)  cin>>a[i];
      for(int j=0;j<m;j++)  cin>>b[j];
      ll i=0, j=0;
      sort(a.begin(),a.end());
      sort(b.begin(), b.end());
      if(a[i]<b[j]){
        ans.push_back(a[i]);    i++;  
      } 
      else{
         ans.push_back(b[j]);   j++; 
      }  
      while(i<n && j<m){
          if(a[i]<b[j]){
              if(a[i]!=ans[ans.size()-1])   ans.push_back(a[i]);
              i++;
          }
          else if(a[i]>=b[j]){
              if(b[j]!=ans[ans.size()-1])   ans.push_back(b[j]);
              j++;
          }
      }
      while(i<n){
            if(a[i]!=ans[ans.size()-1])   ans.push_back(a[i]);
            i++;
      }
      while(j<m){
          if(b[j]!=ans[ans.size()-1])   ans.push_back(b[j]);
          j++;
      }
      cout<<ans.size()<<endl;
  }
  cin.tie(0);
  return 0;
}