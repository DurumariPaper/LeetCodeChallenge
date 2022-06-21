class Trie {
public:
    struct Node
    {
        bool isWord = false;
        Node* child[26] = {NULL};
    }*curr, *root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        
        curr = root;
        for(char c : word)
        {
            if(curr->child[c - 'a'] == NULL)
            {
                Node* data = new Node();
                curr->child[c - 'a'] = data;
            }       
            curr = curr->child[c - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        curr = root;
        for(char c : word)
        {
            if(curr->child[c - 'a'] == NULL)
                return false;
            curr = curr->child[c - 'a'];
        }
        
        if(curr->isWord)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        curr = root;
        for(char c : prefix)
        {
            if(curr->child[c - 'a'] == NULL)
                return false;
            curr = curr->child[c - 'a'];
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