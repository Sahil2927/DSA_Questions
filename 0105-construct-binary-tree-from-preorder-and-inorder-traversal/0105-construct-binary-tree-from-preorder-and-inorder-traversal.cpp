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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode* root=newBuild(preorder,0,preorder.size()-1,
                                inorder,0,inorder.size()-1,mpp);
        return root;
    }
    TreeNode* newBuild(vector<int>& preorder,int preStart,int preEnd,
                        vector<int>& inorder,int inStart, int inEnd,unordered_map<int,int>&mpp){
        if(preStart>preEnd || inStart>inEnd) return NULL;

        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=mpp[root->val]; // to find the index of the root in inorder
        int numsLeft=inRoot-inStart; // to get the number of elements in the left side of the root

        root->left=newBuild(preorder,preStart+1,preStart+numsLeft,
                            inorder,inStart,inRoot-1,mpp);
        root->right=newBuild(preorder,preStart+numsLeft+1,preEnd,
                            inorder,inRoot+1,inEnd,mpp);
        return root;
    }
};