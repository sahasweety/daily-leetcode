#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        // dp[i] stores the max score difference starting from index i
        // We only need the last 4 states to optimize space to O(1), 
        // but an O(n) array is very clean and easy to follow.
        std::vector<int> dp(n + 1, 0);
        
        // Iterate backwards from the end of the array to the beginning
        for (int i = n - 1; i >= 0; --i) {
            // Choice 1: Take 1 stone
            dp[i] = stoneValue[i] - dp[i + 1];
            
            // Choice 2: Take 2 stones
            if (i + 2 <= n) {
                dp[i] = std::max(dp[i], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            }
            
            // Choice 3: Take 3 stones
            if (i + 3 <= n) {
                dp[i] = std::max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
            }
        }
        
        // dp[0] represents Alice's net advantage starting from index 0
        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};