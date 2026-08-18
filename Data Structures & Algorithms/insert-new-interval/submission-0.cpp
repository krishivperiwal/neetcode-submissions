class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int index = 0;
        vector<vector<int>> ans;
        while(index < intervals.size() && newInterval[0] > intervals[index][1]){
            ans.push_back(intervals[index++]);
        }
        if(index == intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int start = min(intervals[index][0],newInterval[0]);
        int end = newInterval[1];
        while(index < intervals.size() && newInterval[1] >= intervals[index][0]){
            end = max(newInterval[1],intervals[index++][1]);
        }
        ans.push_back({start,end});
        while(index < intervals.size()){
            ans.push_back(intervals[index++]);
        }
        return ans;
    }
};
