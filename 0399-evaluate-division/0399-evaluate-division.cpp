class Solution {
public:
    double bfs(const string& src, const string& dst, unordered_map<string, vector<pair<string, double>>>& adj) {
        // If either variable is missing from the graph, division is impossible
        if (adj.find(src) == adj.end() || adj.find(dst) == adj.end()) {
            return -1.0;
        }
        
        // Edge case: if source and destination are the same
        if (src == dst) {
            return 1.0;
        }
        
        // Queue stores pairs of {current_node, cumulative_product}
        queue<pair<string, double>> q;
        unordered_set<string> visited;
        
        q.push({src, 1.0});
        visited.insert(src);
        
        while (!q.empty()) {
            auto [curr, curr_val] = q.front();
            q.pop();
            
            if (curr == dst) {
                return curr_val;
            }
            
            for (const auto& neighbor : adj[curr]) {
                string next_node = neighbor.first;
                double edge_weight = neighbor.second;
                
                if (visited.find(next_node) == visited.end()) {
                    visited.insert(next_node);
                    q.push({next_node, curr_val * edge_weight});
                }
            }
        }
        
        return -1.0; // Destination unreachable
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Map to store the graph: node -> list of {neighbor, weight}
        unordered_map<string, vector<pair<string, double>>> adj;
        
        // Populate the graph with both forward and inverse edges
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }
        
        vector<double> results;
        for (const auto& query : queries) {
            results.push_back(bfs(query[0], query[1], adj));
        }
        
        return results;
    }
};