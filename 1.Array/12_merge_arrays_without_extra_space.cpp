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

// Optimal Solution
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
 
void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); 
         gap > 0; gap = nextGap(gap)) 
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
 
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0; 
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
 
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}



int main(){
    return 0;
}