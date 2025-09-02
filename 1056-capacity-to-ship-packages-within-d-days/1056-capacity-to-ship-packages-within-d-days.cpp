class Solution {
public:
    bool canTake(vector<int>&arr,int mid , int days){
        int countdays = 1;
        int sum = 0;
        for(int i = 0 ; i < arr.size() ; i++){
            sum += arr[i];
            if(sum > mid){
                countdays++;
                sum = arr[i];
            }
            
        }
        return countdays <= days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int minWeight = 0;
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        while(l <= r){
            int mid = (l+r)/2;
            if(canTake(nums,mid,days)){
                minWeight = mid;
                r = mid - 1;
            }
            else l = mid + 1 ;
        }
        return minWeight;
    }
};