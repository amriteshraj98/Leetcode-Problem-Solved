class Solution {
public:
    static const int INF = 1e9;
    vector<vector<int>> dp;
    int limit;
    int solve(int i , int n){
        if (n == 0) return 0;
        if (n < 0) return 1e9;
        if (i*i > n) return 1e9;
        if(dp[i][n] != -1) return dp[i][n];
        int take = 1 + solve(i, n - i*i);
        int skip = solve(i + 1, n);
        return dp[i][n] = min(take, skip);
    }
    int numSquares(int n) {
         limit = (int)std::sqrt(n);
        dp.assign(limit + 2, vector<int>(n + 1, -1));
        return solve(1 , n);
    }
};