class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<int> taken(n,0);
        vector<vector<string>> ans;
        for(int i = 0 ; i < n; i++){
            if(taken[i])continue;
            vector<string> temp;
            temp.push_back(strs[i]);
            for(int j = i + 1; j < n; j++){
                if(taken[j])continue;
                if(anagram(strs[i],strs[j])){
                    temp.push_back(strs[j]);
                    taken[j] = 1;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

    bool anagram(string a,string b){
        if(a.size() != b.size())return false;
        int n = a.size();
        unordered_map<char,int> mp;
        for(int i = 0; i < n;i++){
            mp[a[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(!mp.contains(b[i]))return false;
            mp[b[i]]--;
            if(!mp[b[i]])mp.erase(b[i]);
        }
        return (mp.size() == 0);
    }
};
