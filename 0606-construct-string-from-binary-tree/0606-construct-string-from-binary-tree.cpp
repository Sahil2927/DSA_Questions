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

 //Approach-1 
 //TC=O(N^2)
 //SC=O(N)
// class Solution {
// public:
//     string tree2str(TreeNode* root) {
//         if(root==NULL) return "";

//         string result=to_string(root->val);
        
//         string LEFT= tree2str(root->left);
//         string RIGHT=tree2str(root->right);

//         if(root->left==NULL && root->right==NULL) return result;

//         if(root->left==NULL){
//             return result+"()"+"("+RIGHT+")";
//         }
//         if(root->right==NULL){
//             return result+"("+LEFT+")";
//         }
//         return result+"("+LEFT+")"+"("+RIGHT+")";
//     }
// };

// Approach 2(Optimised)
//TC=O(N)
//SC=O(N)
// The optimized version uses a single, shared string reference (s) passed down the tree. It appends characters directly to the end of the final buffer in a top-down, depth-first order.
class Solution {
public:
    string tree2str(TreeNode* root) {
        string result = "";
        helper(root, result);
        return result;
    }

private:
    void helper(TreeNode* node, string& s) {
        if (!node) return;
        
        s += to_string(node->val);
        
        if (node->left || node->right) {
            s += "(";
            helper(node->left, s);
            s += ")";
        }
        if (node->right) {
            s += "(";
            helper(node->right, s);
            s += ")";
        }
    }
};
