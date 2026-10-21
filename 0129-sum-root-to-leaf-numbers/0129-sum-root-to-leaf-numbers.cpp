/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sumnum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;
        sum = sum * 10 + root->val;
        if (root->left == NULL and root->right == NULL) {
            return sum;
        }
        return sumnum(root->left, sum) + sumnum(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return sumnum(root, sum);
    }
};