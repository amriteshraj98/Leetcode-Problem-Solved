class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0 ;
        int r = n-1;
        int mid = -1;
        while(l <= r){
            mid = (l+r)/2;
            int kitne_missing_number = arr[mid] - (mid+1);
            if(kitne_missing_number < k){
                l = mid + 1;
            }
            else r = mid -1;
        }
        return l + k;
    }
};