class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         stack<int> pq;
        int n = nums2.size();
        vector<int> ans;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!pq.empty() && pq.top() <= nums2[i]) pq.pop();
            if (pq.empty()) ans.push_back(-1);
            else ans.push_back(pq.top());
            pq.push(nums2[i]);
        }

        reverse(ans.begin(), ans.end());

        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = ans[i];
        }

        vector<int> ans2;
        for (int i = 0; i < nums1.size(); i++) {
            ans2.push_back(mp[nums1[i]]);
        }

        return ans2;
    }
};