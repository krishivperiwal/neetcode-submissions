class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        dp.resize(m,vector<int>(n,-1));
        return dfs(0,0,s,t);
    }

    int dfs(int i, int j,string s, string t){
        if(j == t.size())return 1;
        if(i == s.size())return 0;

        if(dp[i][j] != -1)return dp[i][j];

        int take = 0;
        int nTake = dfs(i+1,j,s,t);
        if(s[i] == t[j]){
            take = dfs(i+1,j+1,s,t);
        }
        return dp[i][j] = nTake + take;
    }
};
