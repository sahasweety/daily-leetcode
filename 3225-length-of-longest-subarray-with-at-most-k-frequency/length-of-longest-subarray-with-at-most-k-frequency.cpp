class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        // Reserve space to reduce rehashing overhead for better performance
        std::unordered_map<int, int> freq;
        freq.reserve(nums.size());
        
        int left = 0;
        int max_len = 0;
        
        for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
            freq[nums[right]]++;
            
            // Shrink the window if the frequency exceeds k
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};