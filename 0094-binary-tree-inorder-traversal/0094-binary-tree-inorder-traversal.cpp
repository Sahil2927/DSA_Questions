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
// class Solution {
// public:
//     void inorder(TreeNode* root,vector<int> &result){
//         if(root==nullptr) return;
//         inorder(root->left,result);
//         result.push_back(root->val);
//         inorder(root->right,result);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         inorder(root,result);
//         return result;
//     }
// };
class Solution{
    public:
    vector<int> inorderTraversal(TreeNode* root){
        // stack <TreeNode*> st;
        // TreeNode* node=root;
        // vector<int> inorder;
        // while(true){
        //     if(node!=NULL){
        //         st.push(node);
        //         node=node->left;
        //     }
        //     else{
        //         if(st.empty()==true) break;
        //         node=st.top();
        //         st.pop();
        //         inorder.push_back(node->val);
        //         node=node->right;
        //     }      
        // }

        // Morris Traversal 
        // TC=O(N)
        // SC=O(1)
        vector<int>inorder;
        TreeNode* cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
};