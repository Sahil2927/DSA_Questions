// class Solution {
// public:
//     void DFS(vector<vector<int>>&adj,int u,vector<bool>&visited){
//         visited[u]=true;
//         for(int &v:adj[u]){
//             if(!visited[v]){
//                 DFS(adj,v,visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int V=isConnected.size();
//         vector<vector<int>>adj(V);
//         for(int i=0;i<V;i++){
//             for(int j=0;j<V;j++){
//                 if(isConnected[i][j]==1 && i!=j){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         vector<bool>visited(V,false);
//         int count=0;
//         for(int i=0;i<V;i++){
//             if(!visited[i]){
//                 count++;
//                 DFS(adj,i,visited);
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    void BFS(vector<vector<int>>&adj,int u,vector<bool>&visited){
        visited[u]=true;
        queue<int>q;
        q.push(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v:adj[u]){
                if(!visited[v]){
                    BFS(adj,v,visited);
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(V,false);
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                count++;
                BFS(adj,i,visited);
            }
        }
        return count;
    }
};