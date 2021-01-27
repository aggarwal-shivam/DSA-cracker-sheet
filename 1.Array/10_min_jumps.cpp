int minJumps_dp(int arr[], int n){ // O(n^2) solution using the dynamic programming
    // Your code here
    if(arr[0]==0)    return -1;
    else{
        int jump[n];
        memset(jump,0,sizeof(jump));
        jump[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int remaining=(n-i)-1;
            if(arr[i]>=remaining)   jump[i]=1;
            else if(arr[i]==0)  jump[i]=-1;
            else{
                int start=i+1;
                int end=i+arr[i];
                // int mini=jump[start];
                int mini=100000000;
                int count=0;
                for(int j=start; j<=end; j++){
                    if(jump[j]==-1) count++;
                    else
                        mini=min(mini, jump[j]);    
                }
                if(count==arr[i])   jump[i]=-1;
                else
                    jump[i]=mini+1;
            }
        }
        return jump[0];        
    }

}


int minJumps_optimal(int arr[], int n){ // Optimal solution in O(n)
    if(n<=1)    return 0;
    if(arr[0]==0)   return -1;
    int max_reachable, steps, jumps;
    max_reachable=arr[0];
    steps=arr[0];
    jumps=1;
    int i;
    for(i=1; i<n; i++){
        if(i==n-1)  return jumps;

        max_reachable=max(max_reachable, i+arr[i]);

        steps--;

        if(steps==0){
            jumps++;

            if(i>=max_reachable)    return -1;

            steps=max_reachable-i;
        }
    }
    return -1;
}