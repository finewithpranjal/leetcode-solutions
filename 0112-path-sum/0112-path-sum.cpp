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
    bool res = false;
    void pathsum(TreeNode* root, int k, int sum) {
        if(root == NULL) return;
        sum += root->val;
        // Checking for leaf Node
        if(root->left == NULL and root->right == NULL) {
            if(sum == k) {
                res = true;
                return;
            }
        }
        pathsum(root->left, k, sum);
        pathsum(root->right, k, sum);

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        pathsum(root, targetSum, 0);
        return res;
    }
};