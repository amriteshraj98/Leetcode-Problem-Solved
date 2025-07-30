class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<vector<int>>directions{{-1,0},{0,-1},{1,0},{0,1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>visited(n,vector<int>(n,0));
        auto isSafe = [&](int x , int y){
            return x>=0 && x < n && y>=0 && y < n;
        };
        int ans = 0;
        while(!pq.empty()){
            int diff = pq.top().first;
            auto curr = pq.top().second;
            pq.pop();
            int i = curr.first;
            int j = curr.second;
            if(visited[i][j]) continue;
            visited[i][j] = 1;
            ans = max(ans,diff);
            if(i == n-1 && j == n-1) return ans;
            for(auto dir : directions){
                int new_i = dir[0] + i;
                int new_j = dir[1] + j;
                if(isSafe(new_i,new_j) && !visited[new_i][new_j] ){
                    pq.push({grid[new_i][new_j],{new_i,new_j}});
                }
            }
        }
        return -1;
    }
};