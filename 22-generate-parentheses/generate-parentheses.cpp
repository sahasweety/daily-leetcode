class Solution {
public:
    vector<string> ans;

    void solve(int open, int close, int n, string s) {

        // Base case
        if(open == n && close == n) {
            ans.push_back(s);
            return;
        }

        // We can add '(' if we haven't used all opening brackets
        if(open < n) {
            solve(open + 1, close, n, s + '(');
        }

        // We can add ')' only if there is an unmatched '('
        if(close < open) {
            solve(open, close + 1, n, s + ')');
        }
    }

    vector<string> generateParenthesis(int n) {
        solve(0, 0, n, "");
        return ans;
    }
};