class Solution {
public:

    bool isPossible(vector<int>& candies, long long k, int guess) {

        long long children = 0;

        for (int i = 0; i < candies.size(); i++) {

            children += candies[i] / guess;

            if (children >= k)
                return true;
        }

        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {

        int low = 1;
        int high = 0;

        // Find maximum pile
        for (int i = 0; i < candies.size(); i++) {

            if (candies[i] > high)
                high = candies[i];
        }

        int ans = 0;

        while (low <= high) {

            int guess = low + (high - low) / 2;

            if (isPossible(candies, k, guess)) {

                ans = guess;
                low = guess + 1;      // Try bigger answer
            }
            else {

                high = guess - 1;     // Reduce answer
            }
        }

        return ans;
    }
};