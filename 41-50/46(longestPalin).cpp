string longestPalindrome(string s) {
    int n = s.length();
    
	//max length of the palindrome
    int maxLength = 0;
	//starting index of the longest palindrome
    int startingIndex = 0;
    
    for(int i=0; i<n; i++){
	//expand the string for the odd length palindrome
        int len1 = expand(s, i, i);
		//expand the string for the even length palindrome
        int len2 = expand(s, i-1, i);
        //take the maximum of both 
        int len = max(len1, len2);
        if(len > maxLength){
            maxLength = len;
			the starting index would be before the current index by half the length of the longest palindrome
            startingIndex = i - len/2;
        }
    }
    //return the substring starting from the startingIndex of length maxLength
    return s.substr(startingIndex, maxLength);
}

int expand(string s, int l, int r){
//expand until we are getting an palindrome
    while(l >=0 && r < s.length() && s[l] == s[r]){
        l--;
        r++;
    }
    
	//here - we are returninig r - l - 1 because 'l' and 'r' eacg are gone one steps beyond the actual palindrome.
	//so we need to subtract '2' from the actual length 
	//i.e. (length pf palindrome - 2)
	// (r - l + 1) - 2 = r - l - 1
    return (r - l - 1);
}