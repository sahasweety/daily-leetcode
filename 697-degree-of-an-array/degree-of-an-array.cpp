class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {

        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        // Store frequency, first and last occurrence
        for (int i = 0; i < nums.size(); i++) {

            freq[nums[i]]++;

            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }

            last[nums[i]] = i;
        }

        // Find degree
        int degree = 0;

        for (auto it : freq) {
            degree = max(degree, it.second);
        }

        // Find shortest subarray having same degree
        int ans = nums.size();

        for (auto it : freq) {

            int x = it.first;

            if (freq[x] == degree) {

                int length = last[x] - first[x] + 1;

                ans = min(ans, length);
            }
        }

        return ans;
    }
};