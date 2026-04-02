class Solution {
public:
    int m, n;
    int dp[801][801][3];
    bool visited[801][801][3];

    int solve(int i, int j, int k, vector<vector<int>>& coins) {
        if (i >= m || j >= n) return INT_MIN; // out of bounds
        if (i == m-1 && j == n-1) {
            // At destination: neutralize if negative and we have k left
            if (coins[i][j] < 0 && k > 0) return 0;
            return coins[i][j];
        }

        if (visited[i][j][k]) return dp[i][j][k];
        visited[i][j][k] = true;

        int curr;
        int right, down;

        if (coins[i][j] < 0 && k > 0) {
            // Option 1: neutralize this cell (take 0, use one k)
            right = solve(i+1, j, k-1, coins);
            down  = solve(i, j+1, k-1, coins);
            int neutralized = max(right, down);

            // Option 2: don't neutralize (take negative value)
            right = solve(i+1, j, k, coins);
            down  = solve(i, j+1, k, coins);
            int not_neutralized = coins[i][j] + max(right, down);

            curr = max(neutralized, not_neutralized);
        } else {
            right = solve(i+1, j, k, coins);
            down  = solve(i, j+1, k, coins);
            curr = coins[i][j] + max(right, down);
        }

        return dp[i][j][k] = curr;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        memset(visited, false, sizeof(visited));
        return solve(0, 0, 2, coins); // k=2 neutralizations allowed
    }
};