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
    int maxPath = 0;
public:
    int preorder(TreeNode* root)
    {
        int left = 0, right = 0;
        if(root->left)
        {
            left = preorder(root->left);
        }
        
        if(root->right)
        {
            right = preorder(root->right);
        }
        
               
        if(left + right > maxPath)
            maxPath = left + right;
        
        int result = max(left,right) + 1;
        return result;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        preorder(root);
        return maxPath;
    }
};