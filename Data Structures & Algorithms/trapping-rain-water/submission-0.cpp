class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)return 0;
        vector<int> leftM(n,0);
        vector<int> rightM(n,0);
        leftM[0] = height[0];
        rightM[n-1] = height[n-1];
        for(int i = 1; i < n;i++){
            leftM[i] = max(leftM[i-1],height[i]);
        }
        for(int i = n-2; i >= 0;i--){
            rightM[i] = max(rightM[i+1],height[i]);
        }
        int ans = 0;
        for(int i = 0; i < n;i++){
            ans += min(leftM[i],rightM[i]) - height[i];
        }
        return ans;
    }
};
