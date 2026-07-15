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
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* last = nullptr;
        TreeNode* prev = nullptr;
        
        TreeNode* curr = root;
        
        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // --- Process the node ---
                if (prev != nullptr && curr->val < prev->val) {
                    if (first == nullptr) {
                        first = prev;
                        middle = curr;
                    } else {
                        last = curr;
                    }
                }
                prev = curr;
                // ------------------------
                
                curr = curr->right;
            } else {
                // Find the inorder predecessor of curr
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }
                
                if (pred->right == nullptr) {
                    // Create a temporary link to the root
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Cut the temporary link (restoring the tree)
                    pred->right = nullptr;
                    
                    // --- Process the node ---
                    if (prev != nullptr && curr->val < prev->val) {
                        if (first == nullptr) {
                            first = prev;
                            middle = curr;
                        } else {
                            last = curr;
                        }
                    }
                    prev = curr;
                    // ------------------------
                    
                    curr = curr->right;
                }
            }
        }
        
        // Swap values back to fix the tree
        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};
// class Solution {
// public:
//     TreeNode* first;
//     TreeNode* prev;
//     TreeNode* middle;
//     TreeNode* last;
    
//     void inorder(TreeNode* root){
//         if(!root) return;
//         inorder(root->left);
//         if(prev!=NULL && root->val<prev->val){
//             if(first==NULL){
//                 first=prev;
//                 middle=root;
//             }
//             else{
//                 last=root;
//             }
//         }
//         prev=root;
//         inorder(root->right);
//     }
//     void recoverTree(TreeNode* root) {
//         first=middle=last=NULL;
//         prev= new TreeNode(INT_MIN);
//         inorder(root);
//         if(first && last) swap(first->val,last->val);
//         else if(first && middle) swap(first->val,middle->val);
//     }
// };