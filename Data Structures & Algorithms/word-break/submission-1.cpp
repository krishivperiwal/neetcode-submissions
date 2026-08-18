class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n,-1);
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        return dfs(0,dp,st,s);
    }

    bool dfs(int index,vector<int>&dp,unordered_set<string>& st,string& s){
        if(index == s.size())return true;

        if(dp[index] != -1)return dp[index];

        for(int i = index; i < s.size(); i++){
            if(st.contains(s.substr(index,i-index+1))){
                if(dfs(i+1,dp,st,s)){
                    return dp[index] = 1;
                }
            }
        }

        return dp[index] = 0;
    }
};
