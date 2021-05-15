vector<int> subSetSumK(vector<int> nums, int k){
    int n = nums.size();

    if(n == 0){
        return {};
    }

    sort(nums.begin(), nums.end());

    for(int i=n-1; i>=0 && nums[i] > k; i--){
        nums.pop_back();
    }

    vector<int> temp;
    vector<int> ans;

    solve(nums, temp, ans, k, 0);

    return ans;
}

void solve(vector<int> &nums, vector<int> &temp, vector<int> &ans, int k, int i){

    if(ans.size()){
        return ;
    }

    if(k == 0){
        ans = temp;
    }
    if(i == nums.size()){
        return ;
    }

    temp.push_back(nums[i]);
    solve(nums, temp, ans, k - nums[i], i+1);
    temp.pop_back();
    solve(nums, temp, ans, k , i+1);
}