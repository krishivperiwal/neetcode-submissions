/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>> temp;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            temp.push_back({intervals[i].start,intervals[i].end});
        }
        sort(temp.begin(),temp.end());
        for(int i = 0; i < n-1; i++){
            if(temp[i][1] > temp[i+1][0])return false;
        }
        return true;
    }
};
