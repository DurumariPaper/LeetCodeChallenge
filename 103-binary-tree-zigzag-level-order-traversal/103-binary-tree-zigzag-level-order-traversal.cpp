class Solution {
public:
    
    void zigzagLevelOrder(vector<vector<int>>& result, TreeNode* root, int level)
    {
        if(root == NULL)
            return;
        if(result.size() == level)
        {
            vector<int> emptyBox;
            result.push_back(emptyBox);
        }
        if(level % 2 == 0)
            result[level].push_back(root->val);
        else
            result[level].insert(result[level].begin(), root->val);
        level++;
        if(root->left) zigzagLevelOrder(result, root->left, level);
        if(root->right) zigzagLevelOrder(result, root->right, level); 
    }
    
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        zigzagLevelOrder(result, root, 0);
       /* 
        for(int i = 0 ; i < result.size(); i++)
        {
            if(i % 2 == 1)
            {
                reverse(result[i].begin(), result[i].end());
            }
        }*/
        
        return result;
    }
};