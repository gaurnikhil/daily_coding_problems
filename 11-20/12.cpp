int climbStairs(int n) {
        
        int ans = 1;
        int prevPrev = 1;
        int prev = 1;
        
        for(int i=2; i<=n; i++){
            
            ans = prev + prevPrev;
            
            prevPrev = prev;
            prev = ans;
        }
        
        return ans;
    }
