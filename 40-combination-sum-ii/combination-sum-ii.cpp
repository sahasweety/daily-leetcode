class Solution {
public:

    void solve(int start,
               int target,
               vector<int>& candidates,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Target reached
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates at the same level
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since array is sorted
            if (candidates[i] > target) {
                break;
            }

            // Choose
            temp.push_back(candidates[i]);

            // Each element can be used only once
            solve(i + 1,
                  target - candidates[i],
                  candidates,
                  temp,
                  ans);

            // Undo
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(0, target, candidates, temp, ans);

        return ans;
    }
};