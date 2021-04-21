bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        
        if(m == 0){
            return n == 0;
        }
        
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
        
        dp[0][0] = true;
        
        for(int i=1; i<=m; i++){
            if(p[i-1] == '*' && dp[0][i-2])
                dp[0][i] = true;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }
                
                if(p[j-1] == '*'){
                    if(p[j-2] != s[i-1] && p[j-2] != '.'){
                        dp[i][j] = dp[i][j-2];
                    }
                    else{
                        dp[i][j] = (dp[i-1][j] || dp[i][j-1] || dp[i][j-2]);
                    }
                }
                
            }
        }
        
        return dp[n][m];
    }