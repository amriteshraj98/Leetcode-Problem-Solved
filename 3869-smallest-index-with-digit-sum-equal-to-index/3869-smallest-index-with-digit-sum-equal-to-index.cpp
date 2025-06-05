class Solution {
public:
    int sumofdigit(int n){
        int sum = 0;
        while(n!=0){
            int rem = n%10;
            sum+=rem;
            n = n/10;
        }
        return sum;
    }
    int smallInd = INT_MAX;
    int smallestIndex(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++){
            int num = sumofdigit(nums[i]);
            if(num==i){
                int ind = i ;
                smallInd = min(smallInd,ind);
            }
        }
        if(smallInd == INT_MAX) return -1;
        return smallInd;
    }
};