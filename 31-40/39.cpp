void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    if(n == 0)
        return ;
    int m = board[0].size();
    if(m == 0)
        return ;
    //direction to iterate in all 8 directions (using a nested for loop)
    vector<int> drxn = {0,1,-1};
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
		//initialize the lives around the current block as 0
            int lives = 0;
            
			//iterate in all 8 directions
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    
                    if(k == 0 && l == 0){
                        continue;
                    }
                    
                    int x = i + drxn[k];
                    int y = j + drxn[l];
                    
					//if the eligible adjecent block has live then increase the lives variable
                    if(x >= 0 && x < n && y >= 0 && y < m && abs(board[x][y]) == 1){
                        lives++;
                    }
                }
            }
            
			//now condition : if a block is alive :
			//1. if it has less than 2 lives in neighbour then it dies of underpopulation
			//2. if it has more than 3 live in neighbout then it dies of overpopulation
            if(board[i][j] == 1 && (lives < 2 || lives > 3)){
			//we denote the dead in the next generation as -1 for now
                board[i][j] = -1;
            }
			//if it is dead and it has 2 or 3 lives in neighbour then i live in the next generation
            else if(board[i][j] == 0 && lives == 3){
			//we denote the dead come to lives as 2 for now
                board[i][j] = 2;
            }
        }
    }
    
	//if a block value is more than zero then it lives
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] > 0){
                board[i][j] = 1;
            }
            else{
                board[i][j] = 0;
            }
        }
    }
    
    return ;
}