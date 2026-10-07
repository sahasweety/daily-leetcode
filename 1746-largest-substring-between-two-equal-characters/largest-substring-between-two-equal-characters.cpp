class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        int first[26];

        // Initialize first occurrence as -1
        for (int i = 0; i < 26; i++) {
            first[i] = -1;
        }

        int ans = -1;

        for (int i = 0; i < s.size(); i++) {

            int index = s[i] - 'a';

            // First occurrence
            if (first[index] == -1) {
                first[index] = i;
            }
            else {
                // Characters between equal characters
                int len = i - first[index] - 1;

                ans = max(ans, len);
            }
        }

        return ans;
    }
};