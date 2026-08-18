class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size())return 0;
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(auto it:st){
            if(!st.contains(it-1)){
                int num = it;
                int len = 1;
                while(st.contains(num + 1)){
                    num++;
                    len++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};
