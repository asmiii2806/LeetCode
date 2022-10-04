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
     bool pathsum(TreeNode* root, int currentvalue, int targetSum)
    {
        if(root==NULL)
            return false ;
        
        if(root->left==NULL && root->right==NULL)
        {
            return targetSum == currentvalue + root->val;
        }
        return pathsum(root->left,currentvalue+(root->val),targetSum) ||
           pathsum(root->right,currentvalue+(root->val),targetSum);      
      }
    
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        return pathsum(root,0,targetSum);
        
    }
    

        
};