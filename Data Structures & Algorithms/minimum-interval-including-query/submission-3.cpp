class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        sort(intervals.begin(),intervals.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int j = 0;    
        int n = intervals.size();
        vector<int> ans(q.size(),-1);
        for(int i = 0; i < q.size(); i++){
            while(j < n && q[i].first >= intervals[j][0]){
                pq.push({intervals[j][1] - intervals[j][0] + 1,intervals[j][1]});
                j++;
            }
            while(!pq.empty() && pq.top().second < q[i].first){pq.pop();}
            ans[q[i].second] = pq.empty() ? -1:pq.top().first;
        } 
        return ans;
    }
};
