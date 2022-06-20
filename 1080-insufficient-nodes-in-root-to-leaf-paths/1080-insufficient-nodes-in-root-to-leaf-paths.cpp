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
    bool sufficient(TreeNode* root, int sum, int limit)
    {
        if(root == NULL)
            return false;
        
        if(root->left == NULL and root->right ==NULL)
        {
            if(limit <= sum + root->val)
                return true;
            return false;
        }

        if(!sufficient(root->left, sum + root->val, limit))
        {
            if(root->left != NULL)
            {
                delete root->left;
                root->left = NULL;
            }          
        }
        if(!sufficient(root->right, sum + root->val, limit))
        {
            if(root->right != NULL)
            {
                delete root->right;
                root->right = NULL;
            }            
        }
        
        if(root->left == NULL and root->right ==NULL)
            return false;
        
        return true;
        
    }
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        
        if(!sufficient(root, 0, limit))
        {
            if(root != NULL)
            {
                root = NULL;
            }
        }
        return root;
    }
};