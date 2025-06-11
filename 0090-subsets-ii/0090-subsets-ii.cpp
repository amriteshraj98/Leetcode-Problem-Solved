class Solution {
public:
    void solve(vector<int>&temp,vector<vector<int>>&subset,int idx,vector<int>&nums){
        subset.push_back(temp);
        for(int i = idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(temp,subset,i+1,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>subset;
        sort(nums.begin(),nums.end());
        solve(temp,subset,0,nums);
        return subset;
    }
};