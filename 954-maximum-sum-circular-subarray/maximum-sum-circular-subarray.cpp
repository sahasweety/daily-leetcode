class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = nums[0];
        int mxEnd = nums[0];
        int mnEnd = nums[0];
        int mxSum = nums[0];
        int mnSum = nums[0];

        for(int i = 1; i < nums.size(); i++){

            total +=nums[i];

            mxEnd = max(nums[i],mxEnd+nums[i]);
            mxSum = max(mxSum , mxEnd);

            mnEnd = min(nums[i], mnEnd+nums[i]);
            mnSum = min(mnSum, mnEnd);
        }

            if(mxSum <0)
             return mxSum; 

            return max(mxSum, total-mnSum);
        }

    
};