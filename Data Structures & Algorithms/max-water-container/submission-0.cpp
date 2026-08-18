class Solution {
public:
    int maxArea(vector<int>& heights) {
        int st = 0;
        int e = heights.size()-1;
        int ans = 0;
        while(st < e){
            ans = max(ans,(e-st)*min(heights[st],heights[e]));
            if(heights[st] > heights[e])e--;
            else{st++;}
        }
        return ans;
    }
};
