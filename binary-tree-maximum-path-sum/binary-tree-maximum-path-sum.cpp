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
    int max = INT_MIN;
public:
    int recursiveSum(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int maxLeft = std::max(recursiveSum(root->left), 0);
        int maxRight = std::max(recursiveSum(root->right), 0);
        
        max = std::max(maxLeft + maxRight + root->val, max);
        return root->val + std::max(maxLeft, maxRight);
    }
    
    int maxPathSum(TreeNode* root) {    
        recursiveSum(root);
        return max;
    }
};