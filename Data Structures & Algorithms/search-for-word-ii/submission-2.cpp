struct Node{
    Node* links[26] = {NULL};
    bool flag = false;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* getLink(char ch){
        return links[ch-'a'];
    }

    bool isEnd(Node* node){
        return node->flag;
    }
};

class Solution {
private:
    Node* root;
    vector<string> ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();

        for(int i = 0; i < words.size(); i++){
            insertWord(words[i]);
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(i,j,board,root,"");
            }
        }
        return ans;
    }   

    void insertWord(string word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->getLink(word[i]);
        }
        node->flag = true;
    }

    void dfs(int r, int c,vector<vector<char>>& board,Node* node,string temp){
        int m = board.size();
        int n = board[0].size();

        char ch = board[r][c];

        if(!node->containsKey(ch))return;

        node = node->getLink(ch);
        temp.push_back(ch);
        if(node->isEnd(node)){
            ans.push_back(temp);
            node->flag = false;
        }
        board[r][c] = '.';

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nc < 0 || nr >= m || nc >= n || board[nr][nc] == '.')continue;

            dfs(nr,nc,board,node,temp);
        }

        board[r][c] = ch;
    }
};
