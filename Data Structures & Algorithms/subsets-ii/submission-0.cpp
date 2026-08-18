class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,{},nums);
        return ans;
    }

    void dfs(int index,vector<int>temp,vector<int>& nums){
        ans.push_back(temp);
        if(index == nums.size())return;
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            dfs(i+1,temp,nums);
            temp.pop_back();
        }
    }
};
