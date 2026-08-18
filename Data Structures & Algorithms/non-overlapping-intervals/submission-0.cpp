class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1];
        });
        int n = intervals.size();
        vector<vector<int>> temp;
        temp.push_back(intervals[0]);
        int j = 0;
        for(int i = 1; i < n; i++){
            if(temp[j][1] > intervals[i][0])continue;
            temp.push_back(intervals[i]);
            j++;
        }
        return n - temp.size();
    }
};
