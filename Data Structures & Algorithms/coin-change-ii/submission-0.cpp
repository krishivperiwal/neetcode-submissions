class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return dfs(0,amount,coins,dp);
    }

    int dfs(int index,int amount, vector<int>& coins,vector<vector<int>>& dp){
        if(index == coins.size()){
            if(!amount)return 1;
            return 0;
        }
        if(!amount)return 1;

        if(dp[index][amount] != -1)return dp[index][amount];

        int nTake = dfs(index+1,amount,coins,dp);
        int take = 0;
        if(amount >= coins[index])take = dfs(index,amount - coins[index],coins,dp);

        return dp[index][amount] = take + nTake;
    }
};
