class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& ans) {
        
        if(vis[node] == 1) return false; // cycle
        if(vis[node] == 2) return true;  // already processed
        
        vis[node] = 1; // visiting
        
        for(int nei : adj[node]) {
            if(!dfs(nei, adj, vis, ans))
                return false;
        }
        
        vis[node] = 2; // processed
        ans.push_back(node);
        
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> vis(numCourses, 0);
        vector<int> ans;
        
        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                if(!dfs(i, adj, vis, ans))
                    return {};
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};