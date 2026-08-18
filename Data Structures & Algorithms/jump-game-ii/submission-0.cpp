class Solution {
public:
    vector<int> dp;
    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return dfs(0,nums);
    }

    int dfs(int index,vector<int>& nums){
        if(index >= nums.size() - 1)return 0;

        if(dp[index] != -1)return dp[index];

        if(nums[index] == 0)return 1e8;
        int ans = 1e8;

        for(int i = 1; i <= nums[index]; i++){
            ans = min(ans,1 + dfs(index + i,nums));
        }
        return dp[index] = ans;
    }
};
