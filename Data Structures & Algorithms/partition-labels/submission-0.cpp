class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26,-1);
        for(int i = 0; i < s.size(); i++){
            last[s[i]-'a'] = i;
        }
        vector<int> ans;
        int index = 0;
        while(index < s.size()){
            int maxi = last[s[index]-'a'];
            for(int i = 0; i < maxi; i++){
                maxi = max(maxi,last[s[i]-'a']);
            }
            ans.push_back(maxi-index+1);
            index = maxi + 1;
        }
        return ans;
    }
};
