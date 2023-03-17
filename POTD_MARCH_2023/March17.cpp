class TrieNode{
    public:
    bool isEnd;
    TrieNode *child[26];
    TrieNode(){
        isEnd = false;
        memset(child, 0, sizeof(child)); //initialize all the children as NULL
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i]-'a';
            if(curr->child[index] == NULL){
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.length(); i++){
            int index = word[i]-'a';
            if(curr->child[index] == NULL) return false;
            curr = curr->child[index];
        }
        return curr->isEnd;  
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i=0; i<prefix.length(); i++){
            int index = prefix[i]-'a';
            if(curr->child[index] == NULL) return false;
            curr = curr->child[index];
        }
        return true;  
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
