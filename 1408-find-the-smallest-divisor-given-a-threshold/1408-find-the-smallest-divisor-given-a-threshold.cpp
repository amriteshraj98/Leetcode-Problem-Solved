class Solution {
    int getMax(vector<int> &nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi, nums[i]);
        }
        return maxi;
    }
    int calDiv(vector<int>& nums, int d){
        int sum= 0;
        for(int i=0;i<nums.size();i++){
            sum += (nums[i] + d - 1) / d;

        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=getMax(nums);
        while(s<=e){
            int mid = s+(e-s)/2;
            int div=calDiv(nums,mid);
            if(div<=threshold){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};