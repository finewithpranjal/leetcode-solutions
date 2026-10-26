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
TreeNode *g1first = NULL, *g1sec = NULL;
TreeNode *g2first = NULL, *g2sec = NULL;
TreeNode *prev = NULL;
int g = 0;
    void fun(TreeNode* root) {
        if (root == NULL)
            return;
        // InORDER Starts from here
        fun(root->left);
        if (prev == NULL) {
            prev = root;
        } else {
            if (root->val <= prev->val) {
                if (g == 0) {
                    g1first = prev;
                    g1sec = root;
                    g++;
                } else {
                    g2first = prev;
                    g2sec = root;
                    g++;
                }
            }
            prev = root;
        }
        fun(root->right);
    }
    void recoverTree(TreeNode* root) { 
        fun(root); 
        if(g == 1) 
        {
            swap(g1first->val, g1sec->val);
        }
        else {
            swap(g1first->val, g2sec->val);
        }
    }
};