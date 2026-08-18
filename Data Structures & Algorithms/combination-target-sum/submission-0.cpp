class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        dfs(0,target,nums,ans,{});
        return ans;
    }

    void dfs(int index,int target,vector<int>& nums,vector<vector<int>>& ans,vector<int> temp){
        if(index == nums.size()){
            if(target == 0)ans.push_back(temp);
            return;
        }

        dfs(index+1,target,nums,ans,temp);
        if(target >= nums[index]){
            temp.push_back(nums[index]);
            dfs(index,target - nums[index],nums,ans,temp);
        }
    }
};
