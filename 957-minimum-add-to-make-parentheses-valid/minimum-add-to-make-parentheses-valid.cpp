class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                balance++;
            }
            else {
                if (balance > 0) {
                    balance--;
                }
                else {
                    // Need to add '('
                    ans++;
                }
            }
        }

        // Remaining '(' need ')'
        return ans + balance;
    }
};