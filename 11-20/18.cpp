#include <bits/stdc++.h>
#include <time.h>
using namespace std;
 
//Solution1 
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0){
            return {};
        }
        
        set<int> s;
        unordered_map<int,int> mp;
        
        vector<int> ans;
        
        int i = 0;
        
        for(; i<k; i++){
            s.insert(nums[i]);
            mp[nums[i]] = i;
        }
        
        int l = 0;
        ans.push_back(*s.rbegin());
        
        for(; i<n; i++){
            
            if(mp[nums[l]] <= l)
                s.erase(nums[l]);
            s.insert(nums[i]);
            mp[nums[i]] = i;
            l++;
            
            ans.push_back(*s.rbegin());
        }
        
        return ans;
}

//Solution2

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n == 0)
            return {};
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i<k; i++){
            if(dq.empty()){
                dq.push_back(i);
            }
            else{
                while(!dq.empty() && nums[dq.back()] <= nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        
        for(int i=k; i<n; i++){
            ans.push_back(nums[dq.front()]);
            
            if(dq.empty()){
                dq.push_back(i);
            }
            else{
                while(!dq.empty() && dq.front() <= i - k ){
                    dq.pop_front();
                }
                while(!dq.empty() && nums[dq.back()] <= nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};



