class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size())return false;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return dfs(0,0,s1,s2,s3,dp);
    }

    bool dfs(int i,int j,string s1,string s2,string s3,vector<vector<int>>& dp){
        if(i + j == s3.size())return true;

        if(dp[i][j] != -1)return dp[i][j];

        bool f1 = false;
        bool f2 = false;

        if(i < s1.size() && s1[i] == s3[i+j]){
            f1 =  dfs(i+1,j,s1,s2,s3,dp);
        }
        if(j < s2.size() && s2[j] == s3[i+j]){
            f2 =  dfs(i,j+1,s1,s2,s3,dp);
        }

        return dp[i][j] = f1||f2;
    }
};
