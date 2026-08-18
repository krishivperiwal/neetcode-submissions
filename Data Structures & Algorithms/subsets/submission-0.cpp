class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(0,nums,{},ans);
        return ans;
    }

    void dfs(int index,vector<int>& nums,vector<int> temp,vector<vector<int>>&ans){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }

        dfs(index+1,nums,temp,ans);
        temp.push_back(nums[index]);
        dfs(index+1,nums,temp,ans);
    }
};
