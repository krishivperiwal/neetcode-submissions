class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            ans= max(ans,dfs(i,nums));
        }
        return ans;
    }

    int dfs(int index,vector<int>& nums){
        if(index == nums.size() - 1 || index == nums.size() - 2)return nums[index];

        if(dp[index] != -1)return dp[index];
        int maxi = 0;
        for(int i = index + 2; i < nums.size();i++){
            maxi = max(maxi,dfs(i,nums));
        }
        return dp[index] = nums[index] + maxi; 
    }
};
