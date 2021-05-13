int ans = 0;


void getCount(int i , unordered_set<int> d1, unordered_set<int> d2, unordered_set<int> v,int n){
//when we reached the end of the board rows then we have a now orientation of the queens so increment the answer
    if(i == n){
        ans++;
    }
    
    for(int j=0; j<n; j++){
        if(d1.find(i+j) == d1.end() && d2.find(j-i) == d2.end() && v.find(j) == v.end()){
            d1.insert(i+j);
            d2.insert(j-i);
            v.insert(j);
            getCount(i+1,d1,d2,v,n);
            d1.erase(i+j);
            d2.erase(j-i);
            v.erase(j);
        }
    }
}

int totalNQueens(int n) {
    
	//these sets basically keeps track that which columns or diagonals have a queen
    unordered_set<int> d1;
    unordered_set<int> d2;
    unordered_set<int> v;
    getCount(0,d1,d2,v,n);
    
    return ans;
}