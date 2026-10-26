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
    bool ans = true;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root) {
       if(root == NULL) return;
       // inorder starts from here 
       inorder(root->left);
       if(prev == NULL) {
        prev = root;
       }
       else {
          if(root->val <= prev->val) {
            ans = false;
          }
            
          prev = root;
       }
       inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};