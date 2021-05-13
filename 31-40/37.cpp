	vector<vector<int> > ans;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        
        solve(nums, 0, temp);
        
        return ans;
    }
    
    void solve(vector<int> nums, int idx, vector<int> temp){
        
        if(idx == nums.size()){
            ans.push_back(temp);
            return ;
        }
        
		//move ahead with and without the current element
        temp.push_back(nums[idx]);
        solve(nums, idx+1, temp);
        temp.pop_back();
        solve(nums,idx+1, temp);
        
        return ;
    }