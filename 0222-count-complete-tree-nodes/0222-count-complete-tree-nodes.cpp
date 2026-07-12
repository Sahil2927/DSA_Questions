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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=countLeft(root);
        int rh=countRight(root);
        if(lh==rh) return pow(2,lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int countLeft(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->left;
        }
        return height;
    }
    int countRight(TreeNode* node){
        int height=0;
        while(node){
            height++;
            node=node->right;
        }
        return height;
    }
};