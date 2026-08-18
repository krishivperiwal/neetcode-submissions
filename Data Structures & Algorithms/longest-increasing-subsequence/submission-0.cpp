class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return dfs(0,nums,dp,-1);
    }

    int dfs(int index,vector<int>& nums,vector<vector<int>>&dp,int last){
        if(index == nums.size())return 0;

        if(dp[index][last+1] != -1)return dp[index][last+1];

        int ntake = dfs(index+1,nums,dp,last);
        int take = 0;
        if(last == -1 || nums[last] < nums[index]){
            take = 1 + dfs(index + 1,nums,dp,index);
        }
        return dp[index][last+1] = max(take,ntake);
    }
};
