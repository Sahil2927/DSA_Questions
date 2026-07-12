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
    void MapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track,int start,TreeNode* &target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start){
                target=node;
            }
            if (node->left) {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*>parent_track;
        TreeNode* target=NULL;

        // Step 1: Map parents and locate the target node pointer
        MapParents(root,parent_track,start,target);
        
        // Step 2: BFS outward from the target node to count minutes
        unordered_map<TreeNode*,bool>visited;

        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int minute=-1;
        while(!q.empty()){
            int size=q.size();
            minute++;
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if (parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        return minute;
    }
};