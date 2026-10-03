class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {

        // Always binary search on smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int n = nums1.size();
        int m = nums2.size();

        int low = 0;
        int high = n;

        int half = (n + m + 1) / 2;

        while (low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = half - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];

            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // Correct partition
            if (l1 <= r2 && l2 <= r1) {

                // Odd number of elements
                if ((n + m) % 2 == 1) {
                    return max(l1, l2);
                }

                // Even number of elements
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }

            // We need to move partition in nums1 to the right
            else if (l1 > r2) {
                high = cut1 - 1;
            }

            // We need to move partition in nums1 to the left
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};