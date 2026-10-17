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
    bool fliptree(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2 == NULL) return true;
        if(root1==NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;

        // check for no flip
        bool r1 = fliptree(root1->left , root2->left);
        bool r2 = fliptree(root1->right, root2->right);
        if (r1 && r2) return true;

        // check for flip
        bool r3 = fliptree(root1->left , root2->right);
        bool r4 = fliptree(root1->right, root2->left);
        return r3 && r4;
    }   
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
       return fliptree(root1, root2);
    }
    
};