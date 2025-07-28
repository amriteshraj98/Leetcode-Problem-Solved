class Solution {
public:
    bool bfs(int start,
             vector<int>& color,
             vector<vector<int>>& graph)
    {
        queue<int> q;
        color[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int v : graph[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } 
                else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                if (!bfs(i, color, graph)) 
                    return false;
            }
        }
        return true;
    }
};
