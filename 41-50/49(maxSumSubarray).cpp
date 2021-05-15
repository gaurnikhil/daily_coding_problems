int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if(n == 0){
        return 0;
    }
    
    int ans = INT_MIN;
	//initialize a sum
    int sum = 0;
    
    for(int i=0; i<n; i++){
	//add the current element to the sum
        sum += nums[i];
        
        ans = max(ans, sum);
		
        //if our sum gets -ve then their are two cases
		//1. if the next element is negative then it only will get worse
		//2. if the next element is positive then it will of sure increase by if we just change our sum to zero
		//like discard all the elements those were contribution to the sum then we'll get a better sum
		
        if(sum < 0){
            sum = 0;
        }
    }
    
    return ans;
}