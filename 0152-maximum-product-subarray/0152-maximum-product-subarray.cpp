class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int n = nums.size();
        int product = 1;
        int maxproduct = INT_MIN;
        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j < n ; j++){
                product = product*nums[j];
                maxproduct = max(maxproduct,product);
            }
            product = 1;
        }
        return maxproduct;
    }
};