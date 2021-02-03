#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int b[], int n, int m) {
	    // code here
	    int picked;
	    int j;
	    for(int i=0;i<n;i++){
	        if(b[0]<a[i]){
	            picked=a[i];
	            a[i]=b[0];
	            for(j=0;j<m-1;j++){
	                if(b[j+1]<picked)   b[j]=b[j+1];
	                else{
	                    break;
	                }
	            }
	            b[j]=picked;
	        } 
	    }
	}

int main(){
    return 0;
}