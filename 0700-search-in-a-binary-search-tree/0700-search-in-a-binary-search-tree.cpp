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
    TreeNode* ans;
    void bst(TreeNode* root, int key) {
        if(root==NULL) return;
        if(root->val == key) {
            ans = root;
            return;
        }
        if(root->val < key) {
        // go to right
        bst(root->right, key);
        }
        else {
        // go to left
        bst(root->left, key);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root== NULL) return NULL;
        bst(root, val);
        return ans;
    }
};