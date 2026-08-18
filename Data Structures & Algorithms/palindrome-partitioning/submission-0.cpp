class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        dfs(0,s,temp);
        return ans;
    }
    
    void dfs(int index,string s,vector<string>& temp){
        if(index == s.size())ans.push_back(temp);

        for(int j = index+1; j < s.size() + 1;j++){
            if(pal(s.substr(index,j-index))){
                temp.push_back(s.substr(index,j-index));
                dfs(j,s,temp);
                temp.pop_back();
            }
        }
    }

    bool pal(string temp){
        int i = 0;
        int j = temp.size()-1;
        while(i < j){
            if(temp[i++] != temp[j--])return false;
        }
        return true;
    }
};
