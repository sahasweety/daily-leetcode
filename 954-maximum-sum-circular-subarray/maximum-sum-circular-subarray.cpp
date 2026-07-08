class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int total = 0;

        int mxEnd = nums[0], mnEnd = nums[0];
        int mxSum = nums[0], mnSum = nums[0];

        for (int i = 0; i < nums.size(); i++) {

            total += nums[i];

            if (i == 0) continue;

            mxEnd = max(nums[i], mxEnd + nums[i]);
            mxSum = max(mxSum, mxEnd);

            mnEnd = min(nums[i], mnEnd + nums[i]);
            mnSum = min(mnSum, mnEnd);
        }

        if (mxSum < 0)
            return mxSum;

        return max(mxSum, total - mnSum);
    }
};