class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
        return dfs(0,nums);
    }

    bool dfs(int index,vector<int>& nums){
        if(index >= nums.size() - 1)return true;
        
        if(dp[index] != -1)return dp[index];

        if(!nums[index])return false;

        for(int i = 1; i<= nums[index]; i++){
            if(dfs(index + i,nums))return dp[index] = true;
        }
        return dp[index] = false;
    }
};
