set<string> dict;
unordered_map<string, vector<string>> dp;

vector<string> solve(string s){
    //if we have encountered the same string before then just return the respective result stored in the dp mapping.
    if(dp.find(s) != dp.end()){
        return dp[s];
    }
    
    vector<string> ans;
    
	//if whole string is present in the dictionary then add the string to the result array.
	//(this will basically word as the terminating condition for our recursive call)
    if(dict.find(s) != dict.end()){
        ans.push_back(s);
    }
    
    for(int i=1; i<=s.length(); i++){
        string right = s.substr(i); 
		
		//check if the right substring is present in the dictionary or not
        if(dict.find(right) != dict.end()){
		
		//if yes then recursively check for the left substring
            vector<string> temp = solve(s.substr(0,i));
            
			//now the crutial part --- we need to append the array we got from our recursive call to the result with adding the right substring to every each of its string.
			// eg. is we have catsand, lets say we are on 4th character('s') so sand is present in out dictionary(as given in the sample).
			//not when we called the recursive call for "cat" so we got an array comtaining cat (ie. ["cat"].
			//this array might have multiple elements its just the case..
			//okay, so now we have our right string with us, so we will append that string to every single string 
			//of this string array (temp) and add them to the ans array.
			//just visualize it, you will get it very easily.
			
            for(int j=0; j<temp.size(); j++){
                if(temp[j].length()){
                    ans.push_back(temp[j] + " " + right);
                }
            }
        }
    }
    return dp[s] = ans;
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n = wordDict.size();
    
	
    for(int i=0; i<n; i++){
        dict.insert(wordDict[i]);
    }
    //or dict.insert(wordDict.begin(), wordDict.end());
    
    return solve(s);
    
}
