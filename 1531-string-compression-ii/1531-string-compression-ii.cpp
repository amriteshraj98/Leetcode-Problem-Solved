class Solution {
public:
    int n;
    vector<vector<int>>t;
    int solve(int i , int k , string s){
        if(k < 0 ) return 10000;
        if(i >= n) return 0;
        if(t[i][k] != -1) return t[i][k];
        int delete_i = solve(i+1 , k-1 ,s);
        int keep_i = INT_MAX;
        int addition = 0 , freq = 0 , deleted = 0;
        //"cccdc"
        for(int j = i ; j < n && deleted<=k ; j++){
            if(s[i] == s[j]){
                freq++;
                if(freq == 2 || freq == 10 || freq == 100){
                    addition++;
                }
            }
            else {
                deleted++;
            }
            keep_i = min(keep_i , 1+addition+solve(j+1 , k-deleted,s));
        }
        return t[i][k] =  min(keep_i , delete_i);

    }
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        t = vector<vector<int>>(n+1 , vector<int>(k+1,-1));
        return solve(0 , k , s );
    }
};