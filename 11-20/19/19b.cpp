int paintHouseII(vector<vector<int>> &costs) {
        int n = costs.size();
        if(n == 0){
            return 0;
        }

        int m = costs[0].size();

        vector<int> dp(m);

        int min1 = 0;
        int min2 = 0;

        for(int i=0; i<n; i++){
            int oldMin1 = min1;
            int oldMin2 = min2;

            min1 = INT_MAX;
            min2 = INT_MAX;

            for(int j=0; j<m; j++){
                if(dp[j] != oldMin1 || oldMin1 == oldMin2){
                    dp[j] = oldMin1 + costs[i][j];
                }
                else{
                    dp[j] = oldMin2 + costs[i][j];
                }

                if(dp[j] >= min1){
                    min2 = min(min2, dp[j]);
                }
                else{
                    min2 = min1;
                    min1 = dp[j];
                }
            }

        }

        return min1;
    }
