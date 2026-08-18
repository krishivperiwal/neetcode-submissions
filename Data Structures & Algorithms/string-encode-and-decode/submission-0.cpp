class Solution {
public:
    unordered_map<char,string> mp;
    string encode(vector<string>& strs) {
        string temp;
        for(int i = 0; i < strs.size(); i++){
            mp['a' + i] = strs[i];
            temp.push_back('a' + i);
        }
        return temp;
    }

    vector<string> decode(string s) {
        vector<string> final;
        for(int i = 0; i < s.size(); i++){
            final.push_back(mp['a' + i]);
        }
        return final;
    }
};
