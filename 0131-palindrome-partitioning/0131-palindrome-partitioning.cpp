class Solution {
    bool isPal(string s) {
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] != s[n - i - 1])
                return false;
            i++;
        }
        return true;
    }
    vector<vector<string>> ans;
    void solve(int i, int n, vector<string> v, string s) {
        if (i >= n) {
            ans.push_back(v);
            return;
        }
        for (int j = i; j < n; j++) {
            string st = s.substr(i, j - i + 1);
            if (isPal(st)){
                v.push_back(st);
            solve(j + 1, n, v, s);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        int n = s.size();
        solve(0, n, v, s);
        return ans;
    }
};