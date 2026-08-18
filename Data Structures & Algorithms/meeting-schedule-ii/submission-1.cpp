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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> s,e;
        for(auto it:intervals){
            s.push_back(it.start);
            e.push_back(it.end);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int count  = 0 , ans = 0, i = 0, j = 0;
        while(i < s.size()){
            if(s[i] < e[j]){
                count++,i++;
            }else{
                count--,j++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};
