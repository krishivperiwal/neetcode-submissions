class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if(abs(target) > total)return 0;
        vector<vector<int>> dp(n, vector<int>(2 * total + 1, -1));
        return dfs(0,nums,target,dp,total);
    }
    int dfs(int index,vector<int>& nums, int target,vector<vector<int>>& dp,int offset){
        if(index == nums.size()){
            return target == 0;
        }  

        if(abs(target) > offset)return 0;
        

        if(dp[index][target+offset] != -1)return dp[index][target+offset];

        int add = dfs(index+1,nums,target-nums[index],dp,offset);
        int sub = dfs(index+1,nums,target+nums[index],dp,offset);

        return dp[index][target+offset] = add + sub;
    }
};
