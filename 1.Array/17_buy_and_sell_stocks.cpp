#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        // here we are allowed to buy and sell the stocks atmost once
        int min_so_far, max_diff=0;
        min_so_far=prices[0];
        if(prices.size()==1)    return 0;
        for(int i=1;i<prices.size();i++){
            max_diff=max(max_diff, prices[i]-min_so_far);
            min_so_far=min(min_so_far,prices[i]);
        }
        return max_diff;
    }

int main(){
    return 0;
}