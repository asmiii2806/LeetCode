class Solution
{
public:
    Node* connect(Node* root)
    {
        if(root==NULL)
            return 0;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int currentsize=q.size();
            
            for(int i=0; i<currentsize; i++)
            {
                Node*currentnode=q.front();
                q.pop();
                if(i!= currentsize-1){
                    currentnode->next = q.front();
                }
                if(currentnode->left!=NULL)
                {
                    q.push(currentnode->left);
                }
                if(currentnode->right!=NULL)
                {
                    q.push(currentnode->right);
                }
            }
            
        }
        return root;
            
    }
};