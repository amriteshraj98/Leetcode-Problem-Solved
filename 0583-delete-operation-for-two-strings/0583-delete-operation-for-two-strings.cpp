class Solution {
public:
    int dp[501][501];
    int solve(int i , int j , string word1 , string word2){
        if(i>=word1.length()){
            return word2.length() - j ;
        }
        if(j >= word2.length()){
           return word1.length() - i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j] =  solve(i+1 , j+1 , word1 , word2);
        }
        else {
            return dp[i][j] = 1+min(solve(i+1 , j, word1 , word2),solve(i , j+1 , word1 , word2));
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp , -1 , sizeof(dp));
        return solve(0 , 0 , word1 , word2);
    }
};