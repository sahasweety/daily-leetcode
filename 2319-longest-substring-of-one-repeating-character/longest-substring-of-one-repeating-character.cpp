class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        
        // Set to store lengths of repeating substrings for quick maximum lookup
        multiset<int> lengths;
        // Set to store the intervals [l, r] of repeating characters
        set<pair<int, int>> intervals;
        
        // Helper to add an interval and track its length
        auto add_interval = [&](int l, int r) {
            intervals.insert({l, r});
            lengths.insert(r - l + 1);
        };
        
        // Helper to remove an interval
        auto remove_interval = [&](auto it) {
            lengths.erase(lengths.find(it->second - it->first + 1));
            intervals.erase(it);
        };
        
        // Initialize intervals from the initial string
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            add_interval(i, j - 1);
            i = j;
        }
        
        vector<int> ans;
        ans.reserve(queryIndices.size());
        
        for (size_t k = 0; k < queryIndices.size(); ++k) {
            int idx = queryIndices[k];
            char new_char = queryCharacters[k];
            
            if (s[idx] == new_char) {
                ans.push_back(*lengths.rbegin());
                continue;
            }
            
            // Find the interval containing `idx`
            auto it = intervals.upper_bound({idx, n});
            it--;
            int l = it->first, r = it->second;
            remove_interval(it);
            
            // Split or shrink the current interval and merge with neighbors if characters match
            s[idx] = new_char;
            
            // We split the interval into up to three parts around `idx`
            int curr_l = l;
            if (curr_l <= idx - 1) {
                add_interval(curr_l, idx - 1);
            }
            
            int curr_r = r;
            if (idx + 1 <= curr_r) {
                add_interval(idx + 1, curr_r);
            }
            
            // Add a new single-character interval for idx, then merge if possible
            int new_start = idx, new_end = idx;
            
            // Try merging with left neighbor
            auto left_it = intervals.lower_bound({idx, 0});
            if (left_it != intervals.begin()) {
                auto prev_it = prev(left_it);
                if (prev_it->second == idx - 1 && s[prev_it->first] == new_char) {
                    new_start = prev_it->first;
                    remove_interval(prev_it);
                }
            }
            
            // Try merging with right neighbor
            auto right_it = intervals.upper_bound({idx, n});
            if (right_it != intervals.end()) {
                if (right_it->first == idx + 1 && s[right_it->first] == new_char) {
                    new_end = right_it->second;
                    remove_interval(right_it);
                }
            }
            
            add_interval(new_start, new_end);
            ans.push_back(*lengths.rbegin());
        }
        
        return ans;
    }
};