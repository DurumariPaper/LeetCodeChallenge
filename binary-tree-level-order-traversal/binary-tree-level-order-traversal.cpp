/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void levelOrder(vector<vector<int>>& result, TreeNode* root, int level)
    {
        if(root == NULL)
            return;
        if(result.size() == level)
        {
            vector<int> emptyBox;
            result.push_back(emptyBox);
        }
        result[level].push_back(root->val);        
        level++;
        if(root->left) levelOrder(result, root->left, level);
        if(root->right) levelOrder(result, root->right, level);
        
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(result, root, 0);
        
        return result;
    }
};

/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) { return {}; }
        queue<TreeNode *> q, new_q;
        q.push(root);
        vector<vector<int>> result;
        vector<int> level_n;
        while(!q.empty()) {
            TreeNode * front_node = q.front();
            q.pop();
            level_n.push_back(front_node->val);
            if (front_node->left) {
                new_q.push(front_node->left);
            }
            if (front_node->right) {
                new_q.push(front_node->right);
            }
            if (q.empty()) {
                q = move(new_q);
                result.push_back(move(level_n));
            }
        }
        return result;
    }
};
*/