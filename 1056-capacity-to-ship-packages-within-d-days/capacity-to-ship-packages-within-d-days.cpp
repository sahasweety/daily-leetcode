class Solution {
public:

    bool isPossible(vector<int>& weights, int days, int guess) {

        int currentWeight = 0;
        int requiredDays = 1;

        for (int i = 0; i < weights.size(); i++) {

            if (currentWeight + weights[i] <= guess) {

                currentWeight += weights[i];
            }
            else {

                requiredDays++;
                currentWeight = weights[i];

                if (requiredDays > days)
                    return false;
            }
        }

        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;

        for (int i = 0; i < weights.size(); i++) {

            low = max(low, weights[i]);
            high += weights[i];
        }

        int ans = -1;

        while (low <= high) {

            int guess = low + (high - low) / 2;

            if (isPossible(weights, days, guess)) {

                ans = guess;
                high = guess - 1;      // Try smaller capacity
            }
            else {

                low = guess + 1;       // Increase capacity
            }
        }

        return ans;
    }
};