class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       
      vector<vector<int>>arr(n,vector<int>(n,1e9));
      for(int i=0;i<n;i++) arr[i][i]=0;

       for(auto i:edges){
        int row=i[0];
        int col=i[1];
        int w=i[2];
        arr[row][col]=w;
        arr[col][row]=w;
       }

       for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][via]!=1e9 && arr[via][j]!=1e9){
                arr[i][j]=min(arr[i][j],arr[i][via]+arr[via][j]); 
                }
            }
        }
       }
       int mincity=-1;
       int reachable=n+1;

       for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(i!=j && arr[i][j]<=distanceThreshold){
                count++;
            }
        }
        if(count<=reachable){
            reachable=count;
            mincity=i;
        }
       }
       return mincity;
       
    }
};