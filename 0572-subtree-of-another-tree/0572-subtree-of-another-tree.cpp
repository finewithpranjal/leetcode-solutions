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
    bool subtree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) return true;
        if(p == NULL or q == NULL) return false;
        if(p->val != q->val) return false;
        return subtree(p->left, q->left) and subtree(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(subRoot == NULL) return true;
       if(root == NULL) return false;
       if (subtree(root, subRoot)) {
         return true;
       }
       return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};