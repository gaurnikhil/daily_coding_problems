int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int lengthLongestPath(string input) {
    stringstream ss(input);
    
    string curr;
    int ans = 0;
    
    unordered_map<int,int> pathLength; //to store the path length of every level
	
    //split the string at evert "\n".
    while(getline(ss, curr, '\n')){
        int level = curr.find_last_of("\t"); //find last occurence of "\t" to knowing the current depth/level
        
        string currLevel = (level == string::npos) ? curr : curr.substr(level + 1); //eliminate '\t' from the string
        //if a file exist in the current directory then calculate the length of the path
        if(currLevel.find('.') != string::npos){
            ans = max(ans, pathLength[level - 1] + currLevel.length());
        }
		//else store the length up to the current level.
        else{
            pathLength[level] = pathLength[level - 1] + currLevel.length() + 1;//this plus one is for adding "/" after every directory.
        }
    }
    
    return ans;
}
