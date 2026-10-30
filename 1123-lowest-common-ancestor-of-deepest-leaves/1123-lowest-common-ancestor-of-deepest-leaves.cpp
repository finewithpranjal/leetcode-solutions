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
    int hight(TreeNode* root) {
        if(root == NULL) return 0;
        int l = hight(root->left);
        int r = hight(root->right);
        return l>r?l+1:r+1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      if(root == NULL) return NULL;
      TreeNode* left = lcaDeepestLeaves(root->left);
      TreeNode* right = lcaDeepestLeaves(root->right);

      if(left == NULL && right == NULL) return root;
      else if(left == NULL) return right;
      else if(right == NULL) return left;
      else {
        int a = hight(root->left);
        int b = hight(root->right);

        if(a > b) return left;
        else if(b > a) return right;
        else return root;
      }
    }
};