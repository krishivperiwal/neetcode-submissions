class Solution {
public:
    vector<vector<int>> dp;
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        dp.resize(m+1,vector<int>(n,-1));
        return dfs(0,0,s,p,m,n);
    }

    bool dfs(int i,int j,string s, string p,int m,int n){
        if(j == n){return i == m;}

        if(dp[i][j] != -1)return dp[i][j];

        bool match = (i < m &&(s[i] == p[j] || p[j] == '.'));

        if(j+1 < n && p[j+1] == '*'){
            return dp[i][j] = dfs(i,j+2,s,p,m,n) || (match&&dfs(i+1,j,s,p,m,n));
        }else{
            return dp[i][j] = match&&dfs(i+1,j+1,s,p,m,n);
        }
    }
};
