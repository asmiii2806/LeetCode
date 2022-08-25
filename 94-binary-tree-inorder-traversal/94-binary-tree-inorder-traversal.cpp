
class Solution {
public:
//     CALLLING FUNCTION
    
   // void addLeftSubtree(TreeNode* currentNode,stack<TreeNode* >&s)
   //  {
   //      s.push(currentNode);
   //      while(currentNode->left!=NULL)
   //      {
   //          s.push(currentNode->left);
   //           currentNode=currentNode->left;
   //      }
   //      return;
   // } 
    
//     MAIN GIVEN FUNCTION
    vector<int>inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode *currentNode = root;
        if(root==NULL)
            return ans;
        
        // addLeftSubtree(root,s);
        while(true){
            if(currentNode != NULL){
                st.push(currentNode);
                currentNode = currentNode->left;
            }else{
                if(st.empty() == true) break;
                currentNode = st.top();
                st.pop() ; // in case of q cn = q.front(); q.pop()
                ans.push_back(currentNode->val);
                currentNode = currentNode->right;
            }
        }
        return ans;
    }
};