struct Node{
    Node *links[26] = {NULL};
    bool flag = false;

    Node *getLink(char ch){
        return links[ch -'a'];
    }

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch,Node *node){
        links[ch -'a'] = node;
    }

    bool isEnd(Node *node){
        return node->flag;
    }
};

class PrefixTree {

private:Node *root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node);
            }   
            node = node->getLink(word[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i]))return false;
            node = node->getLink(word[i]);
        }
        return node->isEnd(node);
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->containsKey(prefix[i]))return false;
            node = node->getLink(prefix[i]);
        }
        return true;
    }
};
