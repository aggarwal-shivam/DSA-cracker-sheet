/*
author : Shivam Aggarwal
Problem link : https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
*/

// Counting method
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

//Segregation method
void sort012_method2(int a[], int n)
{
    // coode here 
    int i,low,mid,high;
    low=0;
    mid=0;
    high=n-1;
    while(mid<=high){
        switch(a[mid]){
            case 0:
                swap(a[low++], a[mid++]);
                break;
        
            case 1:
                mid++;
                break;
            case 2:
                swap(a[mid], a[high--]);
                break;
        }
        
    }
    
}