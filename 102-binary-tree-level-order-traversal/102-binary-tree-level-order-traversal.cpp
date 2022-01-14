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
        if(result.size() < level)
        {
            vector<int> emptyBox;
            result.push_back(emptyBox);
        }
        result[level-1].push_back(root->val);        
        level++;
        levelOrder(result, root->left, level);
        levelOrder(result, root->right, level);
        
    }
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrder(result, root, 1);
        
        return result;
    }
};