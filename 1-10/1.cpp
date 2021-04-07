bool checkSum(vector<int> nums, int k){
    int n = nums.size();
    if(n == 0){
        return false;
    }
    
    unordered_set<int> s;
    
    for(int i=0; i<n; i++){
        int num =  k - nums[i];
        if(s.find(num) != s.end()){
            return true;
        }
        
        s.insert(nums[i]);
    }
    
    return false;
}

