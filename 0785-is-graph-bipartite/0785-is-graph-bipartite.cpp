class Solution {
public:
    bool dfs(int curr,int currColor,vector<int>&color,vector<vector<int>>&graph){
        color[curr]=currColor;
        for(int &v:graph[curr]){
            if(color[v]==color[curr]) return false;
            if(color[v]==-1){
                if(!dfs(v,1-currColor,color,graph)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph)) return false;
            }
        }
        return true;
    }
};