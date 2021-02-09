#include<bits/stdc++.h>
using namespace std;

int isPlaindrome(string S)
	{
	    int flag=1;
	    // Your code goes here
	    for(int i=0;i<S.length()/2;i++){
	        if(S[i]!=S[S.length()-i-1]){
	            flag=0;
	            break;
	        }
	    }
	    if(flag==0) return 0;
	    return 1;
	}

int main(){
    return 0;
}