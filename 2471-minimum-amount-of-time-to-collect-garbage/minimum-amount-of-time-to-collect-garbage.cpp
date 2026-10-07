class Solution {
public:
    int garbageCollection(vector<string>& garbage,vector<int>& travel) {

        int n = garbage.size();

        // prefix[i] = time to travel from house 0 to house i
        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + travel[i - 1];
        }

        int ans = 0;

        int lastM = -1;
        int lastP = -1;
        int lastG = -1;

        // Count garbage and find last position
        for (int i = 0; i < n; i++) {

            for (char c : garbage[i]) {

                // Collecting one garbage takes 1 minute
                ans++;

                if (c == 'M') {
                    lastM = i;
                }
                else if (c == 'P') {
                    lastP = i;
                }
                else {
                    lastG = i;
                }
            }
        }

        // Add travel time
        if (lastM != -1) {
            ans += prefix[lastM];
        }

        if (lastP != -1) {
            ans += prefix[lastP];
        }

        if (lastG != -1) {
            ans += prefix[lastG];
        }

        return ans;
    }
};