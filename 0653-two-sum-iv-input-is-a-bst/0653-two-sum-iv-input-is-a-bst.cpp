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
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;

    int getsmallest(){
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* rightchild = small->right;
        while(rightchild){
            asc.push(rightchild);
            rightchild = rightchild->left;
        }
        return small->val;
    }
    int getlargest(){
      TreeNode * large = desc.top();
      desc.pop();
      TreeNode* leftchild = large->left;
      while(leftchild) {
        desc.push(leftchild);
        leftchild = leftchild ->right;
       }
       return large->val;
}
       
    bool findTarget(TreeNode* root, int k) {
        // Left Nodes pushed in stack.
        TreeNode* t = root;
        while(t){
            asc.push(t);
            t=t->left;
        }
        // Right nodes pushed in stack.
        t = root;
        while(t) {
            desc.push(t);
            t = t->right;
        }
        int i = getsmallest();
        int j = getlargest();
        while(i < j) {
            if(i + j == k) return true;
            else if(i+j<k) {
                i = getsmallest();
            }
            else {
                j = getlargest();
            }
        }
        return false;
    }
};