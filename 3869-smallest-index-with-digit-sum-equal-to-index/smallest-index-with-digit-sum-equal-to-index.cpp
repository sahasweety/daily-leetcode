class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the sum of digits of nums[i]
            int digit_sum = 0;
            int temp = nums[i];
            
            // Handle negative numbers if applicable, though usually LeetCode array elements are non-negative
            while (temp > 0) {
                digit_sum += temp % 10;
                temp /= 10;
            }
            
            // Check if the digit sum equals the current index
            if (digit_sum == i) {
                return i;
            }
        }
        return -1;
        
    }
};