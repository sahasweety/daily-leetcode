class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i <nums.size(); i++){
            int v1 = currentSum + nums[i];
            int v2 = nums[i];

            currentSum = max(v1,v2);
            maxSum=max(maxSum,currentSum);
        }
        return maxSum;
        
    }
};