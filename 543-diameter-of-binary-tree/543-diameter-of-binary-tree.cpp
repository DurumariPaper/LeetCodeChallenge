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
        if(root == NULL)
            return 0;
        int left = preorder(root->left);
        int right = preorder(root->right);        
        maxPath = max(maxPath, left + right);        
        return max(left,right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        preorder(root);
        return maxPath;
    }
};