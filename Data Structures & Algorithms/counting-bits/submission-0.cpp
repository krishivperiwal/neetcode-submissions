class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i <= n; i++){
            int temp = 0;
            int num = i;
            while(num){
                temp += num&1;
                num >>= 1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
