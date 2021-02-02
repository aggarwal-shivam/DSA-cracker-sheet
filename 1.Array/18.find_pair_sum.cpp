#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[],int low, int high,int key){
    int temp, flag=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(a[mid]==key){
                temp=mid;
                flag=1;
                high=mid-1;
            } 
            else if(a[mid]>key){
                high=mid-1;
            }
            else if(a[mid]<key){
                low=mid+1;
            }
        }
        if(flag==0) return -1;
        return temp;
    }
    
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans=0;
        for(int i=0;i<n-1;i++){
            int indexy=binary_search(arr,i+1,n-1,k-arr[i]);
            int tempy=0;
                if(indexy!=-1){
                    tempy=0;
                    // cout<<indexy<<endl;
                    while(arr[indexy]==k-arr[i]){
                        ans++;
                        tempy++;
                        indexy++;
                        if(indexy==n)   break;
                    }
                    // cout<<indexy<<endl;
                    // cout<<"***********\n";
                }
        }
        return ans;
    }

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n; i++) cin>>a[i];
    sort(a,a+n);
    // for(int i=0;i<n;i++) cout<<a[i]<<" ";
    // cout<<endl;
    cout<<getPairsCount(a,n,k)<<endl;
    return 0;
}
