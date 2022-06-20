
class Trie{
    public:
    Trie(){
        root = new Node();
    }
    struct Node{
        char val;
        unordered_map<char, Node*> children;
    } *curr, *root;
    
    void addWord(string word)
    {
        curr = root;
        for(int i = word.length() - 1; i >= 0; i--)
        {
            if(curr->children.count(word[i]) == 0)
            {
                Node* data = new Node();
                data->val = word[i];
                curr->children[word[i]] = data;
                
            }
            curr = curr->children[word[i]];
        }
    }
    
    void dfsCount(Node* node, int& result, int depth)
    {
        if(node->children.size() == 0)
        {
            result += depth + 1;
        }
        
        for(auto data : node->children)
        {
            dfsCount(data.second, result, depth + 1);
        }
    }
    
    void dfsCount(int& result)
    {
        for(auto data : root->children)
        {
            dfsCount(data.second, result, 1);
        }
        
    }
};


class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int size = words.size();
        if(size == 1)
            return words[0].length() + 1;
        Trie trie;
        for(string word : words)
        {
            trie.addWord(word);
        }
        int result = 0;
        trie.dfsCount(result);
        
        return result;
    }
};