class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(0,candidates,target,{});
        return ans;
    }
    void dfs(int index,vector<int>& candidates, int target,vector<int> temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        

        for(int i = index;i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1])continue;

            if(candidates[i] > target)break;

            temp.push_back(candidates[i]);
            dfs(i+1,candidates,target-candidates[i],temp);
            temp.pop_back();
        }
    }
};
