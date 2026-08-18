struct Node{
    Node *links[26] = {NULL};
    bool flag = false;

    bool isEnd(Node *node){
        return node->flag;
    }

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* getLink(char ch){
        return links[ch - 'a'];
    }
};

class WordDictionary {
private:Node *root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->getLink(word[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        return dfs(root,word,0);
    }

    bool dfs(Node *node,string word,int index){
        if(index == word.size())return node->flag;

        if(word[index] != '.'){
            if(!node->containsKey(word[index]))return false;
            return dfs(node->getLink(word[index]),word,index+1);
        }

        for(int i = 0; i < 26; i++){
            if(node->containsKey('a' + i)){
                if(dfs(node->getLink('a' + i),word,index+1))return true;
            }
        }
        return false;
    }
};
