class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i = 0;i < nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            auto [num,freq] = it;
            pq.push({freq,num});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++){
            auto [freq,num] = pq.top();
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};
