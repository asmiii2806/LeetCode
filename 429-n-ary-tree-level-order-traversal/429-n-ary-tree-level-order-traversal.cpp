/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        vector<int>a;
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                a.push_back(temp->val);
                for(int i=0;i<temp->children.size();i++)
                {
                    q.push(temp->children[i]);
                }
            }
            else
            {
                ans.push_back(a);
                a.clear();
                if(!q.empty())
                    q.push(NULL);
                else
                    break;
            }
        }
        return ans;
    }
    
};