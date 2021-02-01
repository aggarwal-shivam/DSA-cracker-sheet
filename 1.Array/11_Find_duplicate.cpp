int findDuplicate_map(vector<int>& nums) {
        map<int,int> m;
        for(auto e:nums){
            m[e]+=1;
        }
        int ans;
        for(auto e : m){
            if(e.second > 1){
                ans= e.first;
                break;
            }
        }
        return ans;
    }