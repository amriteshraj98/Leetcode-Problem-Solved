class Solution {
public:
    typedef pair<int,int>p;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto vec : times){
            int u = vec[0];
            int v = vec[1];
            int wt = vec[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,k});
        vector<int>res(n+1,INT_MAX);
        res[k] = 0;        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int v = it.first;
                int wt = it.second;

                if(dist + wt < res[v]){
                    res[v] = dist + wt;
                    pq.push({dist+wt , v});
                }
            }
        }
         int ans = INT_MIN;
        
        for(int i = 1; i <= n; i++)
            ans = max(ans, res[i]);
        
	    return ans == INT_MAX ? -1 : ans;
    }
};