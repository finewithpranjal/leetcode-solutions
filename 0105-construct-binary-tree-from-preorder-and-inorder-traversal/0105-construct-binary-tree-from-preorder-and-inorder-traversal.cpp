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
    unordered_map<int, int> mpp;
    int idx = 0;
    TreeNode* maketree(vector<int>& preorder, int low, int high) {
        if(low > high) return NULL;
        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = mpp[node->val];
        node->left = maketree(preorder, low, id-1);
        node->right = maketree(preorder, id+1, high);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i<inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return maketree(preorder, 0, inorder.size()-1);
    }
};