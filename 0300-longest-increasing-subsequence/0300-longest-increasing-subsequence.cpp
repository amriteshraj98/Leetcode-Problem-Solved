class Solution {
public:
    int n;
    int dp[2501][2500+1];
    int solve(vector<int>&nums,int i , int p ){
        if(i == n ) return 0 ;
        int take = 0 ;
        if(p != -1 && dp[i][p]!=-1) return dp[i][p];
        if(p == -1 || nums[p]<nums[i]){
            take = 1 + solve(nums,i+1,i);
        }
        int skip = 0 + solve(nums,i+1,p);
        if(p != -1 ) dp[i][p] = max(take,skip);
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int i = 0 ;
        int prev_idx = -1;
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,i , prev_idx);
    }
};