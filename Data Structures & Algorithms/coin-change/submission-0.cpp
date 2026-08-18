class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans = dfs(0,amount,coins,dp); 
        return ans == 1e8?-1:ans;       
    }

    int dfs(int index,int target,vector<int>& coins,vector<vector<int>>& dp){
        if(index == coins.size()){
            if(!target)return 0;
            return 1e8;
        }
        if(!target)return 0;

        if(dp[index][target] != -1)return dp[index][target];

        int nTake = dfs(index+1,target,coins,dp);
        int take = 1e8;
        if(target >= coins[index])take = 1 + dfs(index,target-coins[index],coins,dp);

        return dp[index][target] = min(take,nTake); 
    }
};
