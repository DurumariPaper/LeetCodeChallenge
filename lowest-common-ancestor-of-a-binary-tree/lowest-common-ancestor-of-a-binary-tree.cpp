/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* answer;
public:
    
    bool isExist(TreeNode* root, TreeNode* p , TreeNode* q)
    {        
        int ret = 0;
        
        if(root->left)
        {
            ret += isExist(root->left, p, q) ? 1 : 0;
        }
        
        if(root->right)
        {
            ret += isExist(root->right, p, q) ? 1 : 0;
        }
        
        
        if(root == p || root == q)
        {
           ret++;
        }
        
        if(ret >= 2)
            answer = root;
        
        return ret > 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
            return root;
        
        isExist(root, p, q);
        return answer;
    }
};