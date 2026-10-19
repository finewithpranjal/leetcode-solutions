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
    TreeNode* lca = NULL;
    void lcaOfBst(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return ;
        if(root==p or root==q) {
            lca = root;
            return;
        }
        if(root->val < p->val) {
            //go to right..
            lcaOfBst(root->right, p, q);
        }
        else if(root->val > q->val) {
            //go to left..
            lcaOfBst(root->left, p, q);
        }
        else {
            lca = root;
            return;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(p->val < q->val){
        lcaOfBst(root, p, q);
       }
       else {
        lcaOfBst(root, q, p);
       }
       return lca;
    }
};