class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;

        unordered_map<int,int>inDegree;
        unordered_map<int,int>outDegree;

        for(auto &edge : pairs){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
            outDegree[u]++;
        }
        int startNode=pairs[0][0];
        for(auto &it:adj){
            int node=it.first;
            if(outDegree[node]-inDegree[node]==1){
                startNode=node;
                break;
            }
        }

        vector<int> EulerPath; //to store my eulerpath
        stack<int> st; //to perform dfs
        st.push(startNode);

        while(!st.empty()) {
            int curr = st.top();
            if(!adj[curr].empty()) {
                int ngbr = adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            } else {
                EulerPath.push_back(curr);
                st.pop();
            }
        }

        //Build your result
        reverse(begin(EulerPath), end(EulerPath));
        vector<vector<int>> result;
        for(int i = 0; i < EulerPath.size()-1; i++) {
            result.push_back({EulerPath[i], EulerPath[i+1]});
        }

        return result;

    }
};