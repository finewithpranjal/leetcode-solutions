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
    vector<vector<int>> ans;
    void psum(TreeNode* root,int k, vector<int> &res, int sum ){
        if (root == NULL) return; 
        sum += root->val;
        res.push_back(root->val);
        // Checking for leaf node
        if(root->left == NULL and root->right == NULL) {
             if(sum == k){
                ans.push_back(res);
            }
                res.pop_back();
                return;
        }
        psum(root->left, k, res, sum);
        psum(root->right, k, res, sum);
        res.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> res;
    psum(root, targetSum, res, 0);
    return ans;
    }
};