Dp solution using a memoisation array (O(N) space) :-

int numDecodings(string s) {
   int n = s.length();
	
    vector<int> dp(n+1,0);
    
    dp[0] = 1;
    dp[1] = s[0] != '0' ? 1 : 0;
    
    for(int i=2; i<=n; i++){
        if(s[i-1] != '0'){
            dp[i] = dp[i-1];
        }
        
        if(s[i-2] != '0' && ((s[i-1] - '0') + 10*(s[i-2] - '0')) <= 26){
            dp[i] += dp[i-2];
        }
    }
    
    return dp[n];
}
Now since we only need two previous values of the current position so we do not need to maintain
a whole dp array, we can just use two variables eg. prev, prevprev.** (O(1) space)**.

int numDecodings(string s) {
    int n = s.length();
    
	
    int prev = s[0] != '0' ? 1 : 0; //same as dp[1]
    int curr = prev;   //initially our current value will be for 1 character string so it is equal to prev
    int prevprev = 1;  //same as dp[0]
    
    for(int i=2; i<=n; i++){
        curr = 0;
		//for one digit number
        if(s[i-1] != '0'){
            curr = prev;
        }
        //check if the last two digit number is less than 26
        if(s[i-2] != '0' && ((s[i-1] - '0') + 10*(s[i-2] - '0')) <= 26){
            curr += prevprev;
        }
        
        prevprev = prev;
        prev = curr;
    }
    
    return curr;
}
