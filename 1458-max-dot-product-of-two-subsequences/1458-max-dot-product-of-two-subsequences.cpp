class Solution {
public:
int solve(vector<int>&nums1,vector<int>&nums2,int i,int j,int n,int m,vector<vector<int>>&dp){
    if(i==n||j==m){
        return -1e9;
    }
    if(dp[i][j]!=-1e9){
        return dp[i][j];
    }
    int val=nums1[i]*nums2[j]; // take only this pair
    int take_both=(nums1[i]*nums2[j])+solve(nums1,nums2,i+1,j+1,n,m,dp); // take and continue
    int skip_i=solve(nums1,nums2,i+1,j,n,m,dp);
    int skip_j=solve(nums1,nums2,i,j+1,n,m,dp);
    return dp[i][j]=max({val,take_both,skip_i,skip_j});
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1e9));
        return solve(nums1,nums2,0,0,n,m,dp);
    }
};