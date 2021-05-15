class MaxStack {
public:

    stack<int> s;
    stack<int> max;

    MaxStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        if(s.empty()){
            s.push(number);
            max.push(number);
        }
        else{

            int maxElement = max.top();
            if(number > maxElement){
                max.push(number);
            }
            else{
                max.push(maxElement);
            }
            s.push(number);
        }

        return ;
    }

    /*
     * @return: An integer
     */
    int pop() {

        int ans = s.top();

        max.pop();
        s.pop();

        return ans;
    }

    /*
     * @return: An integer
     */
    int top() {
        return s.top();
    }
    
    /*
     * @return: An integer
     */
    int peekMax() {
        return max.top();
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        int maxElement = max.top();
        max.pop();

        stack<int> temp;

        while(s.top() != maxElement){
            temp.push(s.top());
            s.pop();
        }

        s.pop();

        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }

        return maxElement;
    }
};