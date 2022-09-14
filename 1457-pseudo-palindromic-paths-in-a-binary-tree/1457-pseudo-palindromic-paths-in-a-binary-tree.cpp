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
    int ans = 0;
	void solve(TreeNode* root,vector<int>& a){
		if(root==NULL)return;
		a[root->val]+=1;
		solve(root->right,a);
		solve(root->left,a);
		if(root->left==NULL && root->right==NULL){
			int o=0,e=0,total=0;

			for(int i=1;i<10;++i){
				if(a[i]%2){
					o += 1;
				}
				else e += 1;
				total += a[i];
			}

			 if(o<=1){
				if(o==1 && total%2)ans+=1;
				else if(o==0 && total%2==0)ans +=1;
			}
		}
		a[root->val]-=1;
	}
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>a(10);
		solve(root,a);
		return ans;
	

    }
};