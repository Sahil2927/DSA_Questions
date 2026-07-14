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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        
        while (curr) {
            // If both nodes are greater, LCA must be in the right subtree
            if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } 
            // If both nodes are smaller, LCA must be in the left subtree
            else if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } 
            // The split point found (or one of the nodes is the current node)
            else {
                return curr;
            }
        }
        return nullptr;
    }
};