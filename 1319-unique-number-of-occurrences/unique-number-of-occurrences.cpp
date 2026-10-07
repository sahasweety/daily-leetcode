class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> mp;

        // Count frequency of each number
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        unordered_set<int> st;

        // Check whether frequencies are unique
        for (auto it : mp) {

            int freq = it.second;

            if (st.find(freq) != st.end()) {
                return false;
            }

            st.insert(freq);
        }

        return true;
    }
};