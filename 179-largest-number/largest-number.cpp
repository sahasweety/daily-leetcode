class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> a;

        // Convert numbers to strings
        for (int i = 0; i < nums.size(); i++) {
            a.push_back(to_string(nums[i]));
        }

        // Custom sorting
        sort(a.begin(), a.end(), [](string x, string y) {
            return x + y > y + x;
        });

        // Important: all zeros
        if (a[0] == "0") {
            return "0";
        }

        string ans = "";

        for (int i = 0; i < a.size(); i++) {
            ans += a[i];
        }

        return ans;
    }
};