class Solution {
public:
    bool topoSortCheck(vector<int>&indegree,unordered_map<int,vector<int>>&adj,int n){
        queue<int>q;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int v : adj[node]){
                indegree[v]--;
                 if(indegree[v] == 0) {
                    count++;
                    q.push(v);
                }
            }
        }
        if(count == n) //I was able to visit all nodes (course)
            return true; //i.e. I was able to finish all courses
        
        return false; //means there was a cycle and I couldn't complete all courses
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        for(vector<int>vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            // b--->a
            adj[b].push_back(a);
            //indegree kya hoga : a me aa rha hai toh a ki indegree badhegi
            indegree[a]++;
        }
        return topoSortCheck(indegree,adj,numCourses);
    }
};
