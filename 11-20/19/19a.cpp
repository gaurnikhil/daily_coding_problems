int paintHouse(vector<vector<int>> &costs) {
        int n = costs.size();
        int m = 3;

        if(n == 0){
            return 0;
        }

        vector<vector<int> > dp(n,vector<int>(m));

        for(int i=0; i<m; i++){
            dp[0][i] = costs[0][i];
        }

        for(int i=1; i<n; i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][2], dp[i-1][0]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
        }

        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
