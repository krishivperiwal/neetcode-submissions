class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs(n,0,"");
        return ans;
    }

    void dfs(int ln,int rn,string temp){
        if(!ln && !rn)ans.push_back(temp);

        if(ln){
            temp.push_back('(');
            dfs(ln-1,rn+1,temp);
            temp.pop_back();
        }

        if(rn){
            temp.push_back(')');
            dfs(ln,rn-1,temp);
        }
    }
};
