class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,-1);

        return dfs(n,dp,cost);
    }

    int dfs(int n,vector<int>& dp,vector<int>& cost){
        if(n < 0)return 0;
        else if(n == 0)return cost[0];

        if(dp[n] != -1)return dp[n];

        return dp[n] = cost[n] + min(dfs(n-1,dp,cost),dfs(n-2,dp,cost));
    }
};
