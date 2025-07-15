class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(),s.end());
        long long x = stol(s);
        if(x>INT_MAX) return -1;
        if(x>n) return x;
        return -1;

    }
};