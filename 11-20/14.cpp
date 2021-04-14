double estimatePI(){
    int interval = 1000;
    
    double pi, x, y, fromOrigin;
    
    int inCircle = 0;
    int total = 0;
    
    srand(time(NULL));
    
    for(int i = 0; i< interval * interval ; i++){
        x = double(rand() % (interval + 1)) / interval;
        y = double(rand() % (interval + 1)) / interval;
        
        fromOrigin = x*x + y*y;
        
        if(fromOrigin <= 1){
            inCircle++;
        }
        
        total++;
        
        pi = double(4 *inCircle) / total;
    }
    
    return pi;
}
