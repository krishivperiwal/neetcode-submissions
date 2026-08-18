class Solution {
public:
    unordered_map<int,string> mp;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(!digits.size())return ans;
        
        int n = 0;
        for(int i = 2; i <= 9; i++){
            int lim = 3;
            if(i == 7 || i == 9)lim = 4;
            string temp;
            for(int j = 0; j < lim; j++){
                temp.push_back('a' + n++);
            }
            mp[i] = temp;
        }

        dfs(0,digits,"");
        return ans;
    }

    void dfs(int index,string digits,string temp){
        if(index == digits.size()){
            ans.push_back(temp);
            return;
        }  

        int dig = digits[index] - '0';
        for(int i = 0; i < mp[dig].size(); i++){
            temp.push_back(mp[dig][i]);
            dfs(index+1,digits,temp);
            temp.pop_back();
        }
    }
};
