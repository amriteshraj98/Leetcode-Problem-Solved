class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>>t(n,vector<bool>(n,false));
        for(int i = 0 ; i < n ;i++){
            t[i][i] = true;
        }
        int maxlen = 1;
        int idx = 0;
        for(int l = 2 ; l <=n ; l++){
            for(int i = 0 ; (i + l - 1) < n ; i++){
                int j = i+l-1;
                if(s[i]==s[j] && l==2) {
                    t[i][j] = true;
                    maxlen = 2;
                    idx = i;
                }
                else if(s[i]==s[j] && t[i+1][j-1]==true){ // length = 3 or more
                    t[i][j] = true; 
                    maxlen = max(maxlen , j-i+1);
                    idx = i;
                } 
                
            }
        }
        return s.substr(idx,maxlen);
    }
};