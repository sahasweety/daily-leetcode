class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        for (int i = 0; i < words.size(); i++) {

            // First word
            if (ans.empty()) {
                ans.push_back(words[i]);
                continue;
            }

            string a = ans.back();
            string b = words[i];

            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            // If they are not anagrams
            if (a != b) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};