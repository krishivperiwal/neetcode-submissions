class Solution {
public:
    string encode(vector<string>& strs) {
        string temp;
        for(auto s:strs){
            temp += to_string(s.size()) + '#' + s;
        }
        return temp;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#')j++;
            int size = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1
            ,size));
            i = j+size+1;
        }
        return ans;
    }
};
