class Solution {
public:
    int largestInteger(std::vector<int>& nums, int k) {
        int n = nums.size();
        
        // Case 1: k equals the array size
        if (k == n) {
            return *std::max_element(nums.begin(), nums.end());
        }
        
        // Count frequencies of each number
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        // Case 2: k is 1
        if (k == 1) {
            int max_val = -1;
            for (auto& [num, freq] : count) {
                if (freq == 1) {
                    max_val = std::max(max_val, num);
                }
            }
            return max_val;
        }
        
        // Case 3: 1 < k < n
        // Only the first and last elements can possibly appear in exactly one subarray.
        int ans = -1;
        if (count[nums[0]] == 1) {
            ans = std::max(ans, nums[0]);
        }
        if (count[nums[n - 1]] == 1) {
            ans = std::max(ans, nums[n - 1]);
        }
        
        return ans;
    }
};