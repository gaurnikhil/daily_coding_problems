/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

 bool comp(pair<int, string> a, pair<int, string> b){
     
 }

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int n = intervals.size();
        if(n == 0){
            return 0;
        }

        vector<int> st(n);
        vector<int> en(n);

        for(int i=0; i<n; i++){
            st[i] = intervals[i].start;
            en[i] = intervals[i].end;
        }


        sort(st.begin(), st.end());
        sort(en.begin(), en.end());

        int i=0; 
        int j=0;

        int ans = 0;
        int curr = 0;

        while(i < n && j < n){
            if(st[i] <= en[j]){
                curr++;
                i++;
            }
            else{
                curr--;
                j++;
            }
            ans = max(ans, curr);
        }
        while(j < n){
            curr--;
            j++;
        }
        
        while(i < n){
            curr++;
            i++;
        }

        ans = max(ans, curr);

        return ans;
    }
};
