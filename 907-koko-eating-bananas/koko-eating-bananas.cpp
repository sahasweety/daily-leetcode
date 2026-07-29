/***
The helper function does not find the answer; it only checks whether the current guessed answer is valid. Binary Search then uses that result to move left or right.

"This is a Binary Search on Answer problem. I binary search over all possible eating speeds. For each speed, my helper function checks whether Koko can finish all bananas within h hours. If the speed works, I try to minimize it; otherwise, I increase the speed."


Step 1

Guess a speed.

↓

Step 2

Calculate total hours needed at this speed.

↓

Step 3

Can Koko finish within h hours?

↓

YES

This speed is valid.

Try smaller speed.

↓

NO

This speed is too slow.

Increase speed.
*/

/***class Solution {
public:

    int findHours(vector<int>& piles, int speed) {

        int hours = 0;

        for (int pile : piles) {

            hours += pile / speed;

            if (pile % speed != 0)
                hours++;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int hours = findHours(piles, mid);

            if (hours <= h) {

                ans = mid;          // Possible answer
                high = mid - 1;     // Try smaller speed
            }
            else {

                low = mid + 1;      // Need faster speed
            }
        }

        return ans;
    }
};*/

class Solution {
public:

    long long findHours(vector<int>& piles, int speed) {

        long long hours = 0;

        for (int pile : piles) {

            hours += pile / speed;

            if (pile % speed != 0)
                hours++;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            long long hours = findHours(piles, mid);

            if (hours <= h) {

                ans = mid;
                high = mid - 1;
            }
            else {

                low = mid + 1;
            }
        }

        return ans;
    }
};