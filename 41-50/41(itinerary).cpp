unordered_map<string, multiset<string> > travel;
    vector<string> ans;
    
    
    void dfs(string current){
            
        while(travel[current].size() ){
            string next = *travel[current].begin();
            
            travel[current].erase(travel[current].begin());
            
            dfs(next);
        }
        
        ans.push_back(current);
        
        return;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        
        for(int i=0; i<n; i++){
            travel[tickets[i][0]].insert(tickets[i][1]);
        }
                
        dfs("JFK");
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }