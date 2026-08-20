class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, int target, int index, vector<int> v) {

        // Target complete
        if(target == 0) {
            ans.push_back(v);
            return;
        }

        // Array khatam
        if(index == nums.size()) {
            return;
        }

        // -------- TAKE --------
        if(nums[index] <= target) {

            v.push_back(nums[index]);

            // Same index because we can use it again
            solve(nums, target - nums[index], index, v);

            // Backtrack
            v.pop_back();
        }

        // -------- DON'T TAKE --------
        solve(nums, target, index + 1, v);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> v;

        solve(candidates, target, 0, v);

        return ans;
    }
};