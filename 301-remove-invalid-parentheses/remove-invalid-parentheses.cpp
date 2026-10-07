class Solution {
public:

    void solve(string& s, int i,
               int leftRemove, int rightRemove,
               int balance, string cur,
               set<string>& ans) {

        // End of string
        if (i == s.size()) {

            if (leftRemove == 0 &&
                rightRemove == 0 &&
                balance == 0) {

                ans.insert(cur);
            }

            return;
        }

        // --------------------------------
        // Case 1: Current character is '('
        // --------------------------------
        if (s[i] == '(') {

            // Option 1: Remove '('
            if (leftRemove > 0) {
                solve(s, i + 1,
                      leftRemove - 1,
                      rightRemove,
                      balance,
                      cur,
                      ans);
            }

            // Option 2: Keep '('
            solve(s, i + 1,
                  leftRemove,
                  rightRemove,
                  balance + 1,
                  cur + s[i],
                  ans);
        }

        // --------------------------------
        // Case 2: Current character is ')'
        // --------------------------------
        else if (s[i] == ')') {

            // Option 1: Remove ')'
            if (rightRemove > 0) {
                solve(s, i + 1,
                      leftRemove,
                      rightRemove - 1,
                      balance,
                      cur,
                      ans);
            }

            // Option 2: Keep ')'
            // Only possible if we have '(' to match it
            if (balance > 0) {
                solve(s, i + 1,
                      leftRemove,
                      rightRemove,
                      balance - 1,
                      cur + s[i],
                      ans);
            }
        }

        // --------------------------------
        // Case 3: Letter
        // --------------------------------
        else {

            solve(s, i + 1,
                  leftRemove,
                  rightRemove,
                  balance,
                  cur + s[i],
                  ans);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals needed
        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                leftRemove++;
            }
            else if (s[i] == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        set<string> ans;

        solve(s, 0,
              leftRemove,
              rightRemove,
              0,
              "",
              ans);

        return vector<string>(ans.begin(), ans.end());
    }
};