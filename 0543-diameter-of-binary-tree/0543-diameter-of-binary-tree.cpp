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
    int res = 0;
    int diameter(TreeNode* root) {
        if(root == NULL) return 0;
        int left = diameter(root->left);
        int right = diameter(root->right);
        int sum = left+right;
        res = max(res, sum);
        return 1+max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return res;
        
    }
};