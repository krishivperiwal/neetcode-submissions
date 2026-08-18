class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return dfs(0,dp,s);
    }

    int dfs(int index,vector<int>& dp,string&s){
        if(index >= s.size() - 1 && s[index] != '0')return 1;
        if(s[index] == '0')return 0;


        if(dp[index] != -1)return dp[index];

        int one = dfs(index+1,dp,s);
        int two = 0;
        int num = stoi(s.substr(index,2));

        if(num > 9 && num < 27){
            two = dfs(index+2,dp,s);
        }
        return dp[index] = one + two;
    }
};
