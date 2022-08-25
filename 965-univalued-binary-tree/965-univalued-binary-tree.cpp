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
    bool isUnivalTree(TreeNode* root)
    {
        queue<TreeNode*>q;
        int requiredvalue=root->val;
        q.push(root);
        
        while(!q.empty()){
                    TreeNode* currentNode = q.front();
                q.pop();
                
            if(currentNode->val!=requiredvalue)
            {
                return false;
            }

                if(currentNode->left != NULL)
                {
                    q.push(currentNode->left);
                }
            
                if(currentNode->right != NULL)
                {
                    q.push(currentNode->right);
                }
        }
        
        
    return true;
    
        
    }
};