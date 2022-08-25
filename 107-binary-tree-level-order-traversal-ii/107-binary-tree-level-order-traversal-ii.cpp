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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
         vector<vector<int>>ans;
        queue<TreeNode*>q;

        if(root==NULL)
            return ans;
        
        q.push(root);
        
        while(!q.empty())
        {
            
            vector<int>currentlevel;
            int currentSize=q.size();
            
         while(currentSize>0)
         {
            TreeNode* currentNode=q.front();
            q.pop();
            currentlevel.push_back(currentNode->val);
             currentSize-=1;   
            if(currentNode->left!=NULL){
                q.push(currentNode->left);
            }
            if(currentNode->right!=NULL){
                
                q.push(currentNode->right);
            }
        }
        ans.push_back(currentlevel);
     }
                reverse(ans.begin(),ans.end());

    return ans;
    }
};