/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode=q.front();
            q.pop();
            if(currNode==NULL) s.append("#,");
            else s.append(to_string(currNode->val)+',');
            if(currNode!=NULL){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;

        stringstream s(data); // Convert string to a stream for easy parsing.
        string str;
        getline(s,str,','); // Extract the first value up to the comma.


        TreeNode* root=new TreeNode(stoi(str)); // Create the root node using stoi() (string to int).

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str != "#"){
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str != "#"){
                TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));