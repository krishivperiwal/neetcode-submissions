class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int n =nums.size();
        if(total%2 != 0 || n == 1)return false;
        vector<vector<int>> dp(n,vector<int>(total/2 + 1,-1));
        return dfs(0,dp,nums,total/2);
    }

    bool dfs(int index,vector<vector<int>>& dp,vector<int>& nums,int target){
        if(index == nums.size()){
            if(!target)return true;
            return false;
        }
        if(!target)return true;

        if(dp[index][target] != -1)return dp[index][target];

        bool nTake = dfs(index+1,dp,nums,target);
        bool take = false;
        if(nums[index] <= target){
            take = dfs(index+1,dp,nums,target-nums[index]);
        } 
        return dp[index][target] = take||nTake;
    }
};
