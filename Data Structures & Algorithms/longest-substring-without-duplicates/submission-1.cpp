class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int j = 0;
        int ans = 0;
        for(int i = 0; i < s.size();i++){
            if(mp[s[i]] > 0){
                while(s[j] != s[i]){
                    mp[s[j]]--;
                    j++;
                }
                j++;
                mp[s[i]]--;
            }
            mp[s[i]]++;
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};
