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

#slow-fast pointer approach
int findDuplicate(vector<int>& nums) {
        int fast=0, slow=0;
        fast=nums[nums[fast]];
        slow=nums[slow];
        while(fast!=slow){
            fast=nums[nums[fast]];
            slow=nums[slow];
        }
        fast=0;
        while(fast!=slow){
            fast=nums[fast];
            slow=nums[slow];
        }
        return fast;
    }