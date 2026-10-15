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
    void inversed_tree(TreeNode* root) {
        if(root == NULL) return;
        swap(root->left, root->right);
        inversed_tree(root->left);
        inversed_tree(root->right);
        return;
         
    }
    TreeNode* invertTree(TreeNode* root) {
       
        inversed_tree(root);
        return root;
    }
};