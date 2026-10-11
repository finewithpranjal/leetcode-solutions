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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> q; // creating a queue.
        q.push(root);  // first level which contain a single element is
                            // pushed in the queue.
        while (!q.empty()) {
            int lvlsize = q.size();
            vector<int> temp; // creating a temp array that store each
                                       // element of a level
            while (lvlsize--) {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if (t->left != NULL)
                    q.push(t->left);
                if (t->right != NULL)
                    q.push(t->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};