int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0){
        return 1;
    }
            
    for(int i=0; i<n; i++){
	//swap until the nums[i] != i+1 or nums[i] != nums[nums[i]-1] (to avoid infinite loop)
        while(nums[i] > 0 && nums[i] <= n && nums[i] != i+1 && nums[nums[i] - 1] != nums[i]){
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    
    for(int i=0; i<n; i++){
	//if an element is not at its respective place => that element is missing from the array
        if(i+1 != nums[i]){
            return i+1;
        }
    }
    //if all first n numbers are present in the array then return n+1
    return n+1;
}
