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
    vector<double> averageOfLevels(TreeNode* root)
    {
              vector<double>ans;
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            
         int currentlevelsize=q.size();
             
             double sumOfNodes=0;
             
             int count=currentlevelsize;
            
         while(currentlevelsize>0)
         {   
            TreeNode* currentNode=q.front();
            q.pop();
             
             sumOfNodes+=currentNode->val;
             
             currentlevelsize-=1;   
            if(currentNode->left!=NULL){
                q.push(currentNode->left);
            }
            if(currentNode->right!=NULL){
                
                q.push(currentNode->right);
            }
        }
        ans.push_back(sumOfNodes/count);
        
     }
    return ans;       
    }
    
};