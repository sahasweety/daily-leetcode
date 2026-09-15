class Solution {
public:
    int maxPalindromes(string s, int k) {

        int n = s.size();

        // pal[l][r] = true if s[l...r] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Build palindrome table
        for (int len = 1; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {

                int r = l + len - 1;

                if (s[l] == s[r] &&
                    (len <= 2 || pal[l + 1][r - 1])) {

                    pal[l][r] = true;
                }
            }
        }

        // dp[i] = maximum number of palindromes
        // using first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {

            // Don't choose a palindrome ending at i-1
            dp[i] = dp[i - 1];

            // Try every possible starting position
            for (int j = 0; j < i; j++) {

                int len = i - j;

                if (len >= k && pal[j][i - 1]) {

                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};