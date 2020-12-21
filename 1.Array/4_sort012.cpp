/*
author : Shivam Aggarwal
Problem link : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*/

void sort012(int a[], int n)
{
    // coode here 
    int zero,one,two;
    zero=0;
    one=0;
    two=0;
    for(int i=0;i<n;i++){
        if(a[i]==0) zero++;
        if(a[i]==1) one++;
        if(a[i]==2) two++;
    }
    int i=0;
    while(zero--){
        a[i]=0;
        i++;
    }
    while(one--){
        a[i]=1;
        i++;
    }
    while(two--){
        a[i]=2;
        i++;
    }
}