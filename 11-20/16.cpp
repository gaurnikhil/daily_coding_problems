class LogAPI{
  public : 
  
    int *buffer;
    int maxSize = 0;
    int idx = 0;
    
    logAPI(int n){
        this.maxSize = n;
        *buffer = new int(n);
    }
    
    void record(int order_id){
        buffer[idx] = order_id;
        idx = (idx + 1) % maxSize;
    }
    
    
    int getLast(int i){
        return buffer[(idx - i + maxSize) % maxSize];
    }
    
    
};
