
class Solution {
public:
   void rightside(vector<int>&ans, TreeNode* root, int currentlevel)
 {
    if(root==NULL)
        return;
    
    if(ans.size()==currentlevel)
    {
        ans.push_back(root->val);
    }   
    rightside(ans, root->right, currentlevel+1);
    rightside(ans, root->left, currentlevel+1);
    
    return; 
    
}
 
    
    vector<int> rightSideView(TreeNode* root) 
    {
           vector<int>ans;
    
    rightside(ans, root, 0);
    
    return ans; 
        
    }
};