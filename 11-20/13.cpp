int lengthOfLongestSubstringKDistinct(string &s, int k) {
        int n = s.length();
        if(n == 0){
            return 0;
        }
        if(k == 0){
            return 0;
        }
        
        int ans = 0;
        int l = 0;
        unordered_map<char, int> mp;

        for(int i=0; i<n; i++){
            mp[s[i]]++;

            if(mp.size() > k){
                
                while(l < i && mp.size() > k){
                    mp[s[l]]--;
                    if(mp[s[l]] == 0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
            }

            ans = max(ans , i - l + 1);
        }

        return ans;
    }
