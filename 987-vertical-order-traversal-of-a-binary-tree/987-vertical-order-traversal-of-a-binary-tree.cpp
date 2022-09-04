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
  int left = 0;
    int right = 0;
    int height = 0;
    int h_offset = 0;
    
    void findBounds(TreeNode* node, int x, int y) {
        if (node == nullptr) {
            return;
        }
        
        if (x > right) {
            right = x;
        }
        if (x < left) {
            left = x;
        }
        if (y > height) {
            height = y;
        }
        
        findBounds(node->left, x - 1, y + 1);
        findBounds(node->right, x + 1, y + 1);
    }
    
    void fillCube(TreeNode* node, vector<vector<vector<int>>> &treecube, int x, int y) {
        if (node == nullptr) {
            return;
        }
        
        treecube[x + h_offset][y].push_back(node->val);
        fillCube(node->left, treecube, x - 1, y + 1);
        fillCube(node->right, treecube, x + 1, y + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        findBounds(root, 0, 0);
        h_offset = -left;
        
        vector<vector<int>> column(height + 1, vector<int>(0, 0));
        vector<vector<vector<int>>> treecube;
        for (int i = left; i <= right; i++) {
            treecube.push_back(column);
        }
        fillCube(root, treecube, 0, 0);
        
        vector<vector<int>> vot((right - left) + 1, vector<int>(0, 0));
        for (int i = 0; i < treecube.size(); i++) {
            for (int j = 0; j < treecube[i].size(); j++) {
                if (treecube[i][j].size() > 0) {
                    if (treecube[i][j].size() > 1) {
                        sort(treecube[i][j].begin(), treecube[i][j].end());
                        for (int k = 0; k < treecube[i][j].size(); k++) {
                            vot[i].push_back(treecube[i][j][k]);
                        }
                    }
                    else {
                        vot[i].push_back(treecube[i][j][0]);
                    }
                }
            }
        }

        return vot;
    }
};