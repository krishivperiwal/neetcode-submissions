class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> vis(nums.size(),false);
        dfs({},nums,vis);
        return ans;
    }

    void dfs(vector<int> temp,vector<int>& nums,vector<bool> vis){
        if(temp.size() == nums.size())ans.push_back(temp);

        for(int i = 0; i < nums.size(); i++){
            if(vis[i])continue;
            temp.push_back(nums[i]);
            vis[i] = true;
            dfs(temp,nums,vis);
            vis[i] = false;
            temp.pop_back();
        }
    }
};
