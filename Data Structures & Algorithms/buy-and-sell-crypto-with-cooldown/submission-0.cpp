class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n,vector<int>(2,-1)));
        return dfs(0,0,prices,dp,0);
    }

    int dfs(int index,int has,vector<int>& prices,vector<vector<vector<int>>>& dp,int cool){
        if(index == prices.size())return 0;
        if(dp[has][index][cool] != -1)return dp[has][index][cool];

        if(has){
            int nSell = dfs(index+1,has,prices,dp,0);
            int sell = prices[index] + dfs(index+ 1,0,prices,dp,1);
            return dp[has][index][cool] = max(sell,nSell);
        }else{ 
            int nBuy = dfs(index+1,0,prices,dp,0);
            int buy = 0;
            if(!cool){
                buy = dfs(index+1,1,prices,dp,0) - prices[index];
            }
            return dp[has][index][cool] = max(buy,nBuy);
        }
    }
};
