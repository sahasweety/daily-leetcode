class Solution {
public:
    int minSwaps(string s) {
        int balance = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '[') {
                balance++;
            }
            else {
                balance--;
            }

            // Invalid prefix
            if (balance < 0) {
                ans++;

                // We bring a '[' from the right
                balance = 1;
            }
        }

        return ans;
    }
};