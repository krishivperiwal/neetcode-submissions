class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        dp.resize(m+1,vector<int>(n+1,-1));
        return dfs(0,0,word1,word2);
    }

    int dfs(int i,int j,string word1, string word2){
        if(j == word2.size()){
            if(i == word1.size())return 0;
            return word1.size() - i;
        }
        if(i == word1.size())return word2.size() - j;

        if(dp[i][j] != -1)return dp[i][j];
        
        if(word1[i] == word2[j]){
            return dp[i][j] = dfs(i+1,j+1,word1,word2);
        }
        int del = 1 + dfs(i+1,j,word1,word2);
        int rep = 1 + dfs(i+1,j+1,word1,word2);
        int add = 1 + dfs(i,j+1,word1,word2);

        int mini = min(del,rep);
        return dp[i][j] = min(add,mini);
    }
};
