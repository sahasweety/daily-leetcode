class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;

        // Score outside all parentheses
        st.push(0);

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                // Start a new level
                st.push(0);
            }
            else {
                // Score inside current parentheses
                int cur = st.top();
                st.pop();

                int score;

                if (cur == 0) {
                    // ()
                    score = 1;
                }
                else {
                    // (A)
                    score = 2 * cur;
                }

                // Add score to previous level
                st.top() += score;
            }
        }

        return st.top();
    }
};