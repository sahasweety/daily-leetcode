class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                low++;
                high++;
            }

            else if (s[i] == ')') {
                low--;
                high--;
            }

            else { // '*'
                low--;
                high++;
            }

            // Minimum balance cannot be negative
            low = max(0, low);

            // Even maximum balance is negative
            // means impossible
            if (high < 0) {
                return false;
            }
        }

        return low == 0;
    }
};