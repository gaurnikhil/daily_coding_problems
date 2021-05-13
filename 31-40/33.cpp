class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int> lowers;
    priority_queue<int, vector<int>, greater<int> > highers;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lowers.push(num);
        
        highers.push(lowers.top());
        lowers.pop();
        
        if(highers.size() > lowers.size()){
            lowers.push(highers.top());
                highers.pop();
        }
        
        return ;
    }
    
    double findMedian() {
        if(lowers.size() > highers.size()){
            return lowers.top();
        }
        else{
            return double(lowers.top() + highers.top()) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */