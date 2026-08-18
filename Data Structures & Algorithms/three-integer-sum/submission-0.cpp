class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n-2;i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int st = i + 1;
            int e = n-1;
            while(st < e){
                if(nums[st] + nums[e] + nums[i] > 0)e--;
                else if(nums[st] + nums[e] + nums[i] < 0)st++;
                else{
                    ans.push_back({nums[st],nums[e],nums[i]});
                    st++,e--;
                    while(st < e && nums[st] == nums[st-1])st++;
                    while(e > i && nums[e] == nums[e+1])e--;
                }
            }
        }
        return ans;
    }
};
