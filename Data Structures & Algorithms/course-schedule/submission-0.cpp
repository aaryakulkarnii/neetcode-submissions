class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        
        if(vis[node] == 1) return false; // cycle found
        if(vis[node] == 2) return true;  // already processed
        
        vis[node] = 1; // mark as visiting
        
        for(int nei : adj[node]) {
            if(!dfs(nei, adj, vis))
                return false;
        }
        
        vis[node] = 2; // mark as completely visited
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> vis(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                if(!dfs(i, adj, vis))
                    return false;
            }
        }
        
        return true;
    }
};