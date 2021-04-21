//just a simple bfs code...self explainatory
//just encounter each level of the traversal and make that node as '1' so that you don't process that again
//once you reach to the destination index somehow then return the answer or you ended up out side the while loop
//then return -1 => its not possible to reach the destination index (ie. n-1,n-1 here).

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if(n == 0 || grid[0][0] == 1){
        return -1;
    }
    
    int ans = 1;
    
    vector<int> dx = {1,-1,0,0,1,-1,-1,1};
    vector<int> dy = {0,0,1,-1,1,-1,1,-1};
    
    queue<pair<int,int> > q;
    q.push({0,0});
    grid[0][0] = 1;
    
    while(!q.empty()){
        int sz = q.size();
        
        for(int i=0; i<sz; i++){
            
            // cout<<ans<<" ";
            
            pair<int,int> curr = q.front();
            q.pop();
            
            int x = curr.first;
            int y = curr.second;
            
            // cout<<x<<" "<<y<<endl;
            
            if((x == n-1) && (y == n-1)){
                return ans;
            }
            
            for(int j=0; j<8; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                    q.push({nx,ny});
                    grid[nx][ny]++;
                }
            }
            
        }
        ans++;
    }
    
    return -1;
}
