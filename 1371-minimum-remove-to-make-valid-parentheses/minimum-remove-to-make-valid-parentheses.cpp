class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> st;

        // First pass
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }

            else if (s[i] == ')') {

                if (!st.empty()) {
                    st.pop();
                }
                else {
                    // Extra ')'
                    s[i] = '#';
                }
            }
        }

        // Any '(' left in stack is invalid
        while (!st.empty()) {
            s[st.top()] = '#';
            st.pop();
        }

        // Build answer
        string ans;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != '#') {
                ans += s[i];
            }
        }

        return ans;
    }
};