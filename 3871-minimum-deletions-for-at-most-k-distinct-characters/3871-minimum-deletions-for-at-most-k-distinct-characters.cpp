class Solution {
public:
    int minDeletion(string s, int k) {
        int n = s.length();

        map<char, int> freq;

        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }

        int x = freq.size();  // current distinct characters

        if (x <= k) return 0;  // already at most k distinct

        int z = x - k;  // number of characters to delete fully

        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Sort vector by frequency ascending
        sort(vec.begin(), vec.end(), [](pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        });

        // Sum the first z frequencies
        int sum = 0;
        for (int i = 0; i < z; i++) {
            sum += vec[i].second;
        }

        return sum;
    }
};