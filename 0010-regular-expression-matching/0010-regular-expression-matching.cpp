class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        // dp[i][j] will be true if s[i..m-1] matches p[j..n-1]
        // The size is (m+1) x (n+1) to handle empty string/pattern cases
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: Empty string matches empty pattern
        dp[m][n] = true;

        // Iterate backwards from the end of the strings
        for (int i = m; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                // Check if the current characters match (or if pattern has '.')
                bool first_match = (i < m && (p[j] == s[i] || p[j] == '.'));
                
                // Case 1: Next character in pattern is '*'
                if (j + 1 < n && p[j + 1] == '*') {
                    // Two options:
                    // 1. Ignore the 'x*' part (move pattern index by 2) -> dp[i][j+2]
                    // 2. If first match is true, consume one char of s, keep pattern -> dp[i+1][j]
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } 
                // Case 2: Next character is NOT '*'
                else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        
        return dp[0][0];
    }
};