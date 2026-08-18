class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())return false;
        int n = s.size();
        unordered_map<char,int> st;
        for(int i = 0; i < n; i++){
            st[s[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(!st.contains(t[i]))return false;
            st[t[i]]--;
            if(st[t[i]] == 0)st.erase(t[i]);
        }
        return (st.size() == 0);
    }
};
