int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0){
            return 0;
        }
        
        int minPrice = INT_MAX;
        int ans = INT_MIN;
        
        for(int i=0; i<n; i++){
            minPrice = min(minPrice, prices[i]);
            
            ans = max(ans, prices[i] - minPrice);
        }
        
        return ans;
    }