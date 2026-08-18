class Solution {
public:
    vector<int> dp;
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        int ans = -1e8;
        for(int i = 0; i < n; i++){
            ans = max(ans,dfs(i,nums));
        }
        return ans;
    }

    int dfs(int index,vector<int>&nums){
        if(index == nums.size())return 0;
        if(dp[index] != -1)return dp[index];
        return dp[index] = max(nums[index],nums[index] + dfs(index + 1,nums));
    }
};
