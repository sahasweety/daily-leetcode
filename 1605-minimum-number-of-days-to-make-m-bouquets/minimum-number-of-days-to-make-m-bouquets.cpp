class Solution {
public:

    bool isPossible(vector<int>& bloomDay, int m, int k, int guess) {

        int flowers = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= guess) {

                flowers++;
            }
            else {

                bouquets += flowers / k;
                flowers = 0;
            }
        }

        bouquets += flowers / k;

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long total = 1LL * m * k;

        if (total > bloomDay.size())
            return -1;

        int low = bloomDay[0];
        int high = bloomDay[0];

        for (int i = 1; i < bloomDay.size(); i++) {

            if (bloomDay[i] < low)
                low = bloomDay[i];

            if (bloomDay[i] > high)
                high = bloomDay[i];
        }

        int ans = -1;

        while (low <= high) {

            int guess = low + (high - low) / 2;

            if (isPossible(bloomDay, m, k, guess)) {

                ans = guess;
                high = guess - 1;
            }
            else {

                low = guess + 1;
            }
        }

        return ans;
    }
};