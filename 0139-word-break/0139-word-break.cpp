class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[301];
    bool helper(string &s , int idx){
        if(idx==n) return true;
        if(st.find(s)!=st.end()) return true;
        if(t[idx]!=-1) return t[idx];
        for(int len=1;len<=n;len++){
            string temp=s.substr(idx,len);
            if(st.find(temp)!=st.end()&& helper(s,idx+len)){
                return t[idx]=true;
            }

        }
        return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        memset(t, -1, sizeof(t));
       for(auto &it :wordDict){
            st.insert(it);
       }
        return helper(s,0);
    }
};