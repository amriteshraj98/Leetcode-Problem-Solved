class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size();
        int cols = strs[0].size();
        vector<int>dp(cols , 1);
        int lis = 1;
        for(int i = 0 ; i < cols ; i++){
            for(int j = 0 ; j < i ; j++){
                bool isvalid = true;
                for(int k = 0 ; k < rows ; k++){
                    // s[j] <= s[i]
                    if(strs[k][j] > strs[k][i]){ // condition break ye col hi bekar ho gya 
                        isvalid = false;
                        break;
                    }
                }
                if(isvalid) dp[i] = max(dp[i] , dp[j]+1); // ek baar bhi invalid nhi hua tha 
            }
            lis = max(lis , dp[i]);
        }
        return cols - lis;
    }
};