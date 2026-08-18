class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        if(!st.contains(endWord))return 0;
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        if(st.contains(beginWord))st.erase(beginWord);


        while(!q.empty()){
            auto[cost,word] = q.front();
            q.pop();

            if(word == endWord)return cost;
            for(int i = 0; i < word.size();i++){
                char ch = word[i];
                for(int j = 0; j < 26; j++){
                    word[i] = 'a' + j;
                    if(st.contains(word)){
                        q.push({cost+1,word});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }

        return 0;
    }
};
