// The rand5() API is already defined for you.
// int rand5();
// @return a random integer in the range 1 to 5

class Solution {
public:
    int rand7() {
        int rand21 = INT_MAX;
        
        while(rand21 >= 21){
            rand21 = (rand5() - 1)*7 + (rand5() - 1);
        }
        
        return rand21 % 10 + 1;
    }
};