

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If the number of citations is greater than or equal to 
            // the number of papers having at least `citations[mid]` citations
            if (citations[mid] >= n - mid) {
                right = mid - 1; // Try to find a larger h-index on the left
            } else {
                left = mid + 1;  // Look for a larger citation value on the right
            }
        }
        
        // `left` points to the first index where citations[mid] >= n - mid
        // Therefore, the total number of valid papers is n - left
        return n - left;
    }
};