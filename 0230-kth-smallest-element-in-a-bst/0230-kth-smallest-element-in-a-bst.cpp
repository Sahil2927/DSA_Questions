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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int count = 0;
        int result = -1; // Stores the final answer

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Process the current node
                count++;
                if (count == k) {
                    result = curr->val;
                    // Do not return immediately; let the loop finish to restore
                    // the tree!
                }
                curr = curr->right;
            } else {
                // Find the inorder predecessor
                TreeNode* prev = curr->left;
                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    // Create temporary thread
                    prev->right = curr;
                    curr = curr->left;
                } else {
                    // Break temporary thread to restore tree
                    prev->right = nullptr;

                    // Process the current node
                    count++;
                    if (count == k) {
                        result = curr->val;
                        // Do not return immediately; let the loop finish to
                        // restore the tree!
                    }
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};