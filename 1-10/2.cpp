vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return {};
        }
        
        vector<int> ans(n,1);
        
        for(int i=1; i<n; i++){
            ans[i] = (nums[i-1]*ans[i-1]);
        }
        
        int r = 1;
        for(int i=n-2; i>=0; i--){
            r *= nums[i+1];
            ans[i] *= r;
        }
        
        return ans;
    }
