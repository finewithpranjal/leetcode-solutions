/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* res = NULL;
    int lca(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node==NULL) return 0;
        int left = lca(node->left, p, q);
        int right = lca(node->right, p, q);
        int self = 0;
        if(node == p or node == q) {
            self=1;
        }
        int total = self + left + right;
        if(total == 2 and res == NULL) {
            res = node;
        }
            return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       lca(root, p, q);
       return res;
        
    }
};