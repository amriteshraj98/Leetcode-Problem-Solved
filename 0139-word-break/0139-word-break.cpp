class Solution {
public:
    int n ;
    unordered_set<string> st;
    int dp[301];
    bool solve(int idx , string s){

        if(idx == n) return true;
        if(dp[idx]!=-1) return dp[idx];

        if(st.find(s)!=st.end()) return true;

        for(int len = 1 ; len < n ; len++){
            string temp = s.substr(idx,len);
            if(st.find(temp)!=st.end() && solve(idx+len,s)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for(auto ch : wordDict) st.insert(ch);
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};