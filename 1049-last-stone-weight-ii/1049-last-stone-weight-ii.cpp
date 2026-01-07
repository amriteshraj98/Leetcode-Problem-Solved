class Solution {
public:
    int tSum, target;
    vector<vector<int>> dp;

    int solve(vector<int>& stones, int idx, int sum) {
        if (idx == stones.size() || sum >= target) {
            return abs(sum - (tSum - sum));
        }

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        return dp[idx][sum] = min(solve(stones, idx + 1, sum + stones[idx]),
                                  solve(stones, idx + 1, sum));
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        tSum = accumulate(begin(stones), end(stones), 0);

        target = ceil(tSum / 2);
        dp.resize(n, vector<int>(target + 1, -1));

        return solve(stones, 0, 0);
    }
};