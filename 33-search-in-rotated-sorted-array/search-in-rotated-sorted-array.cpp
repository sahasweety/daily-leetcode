class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = (high + low) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            //low <= mid . we check ki if low < mid se then its sorted . AND if sorted then hum check krege ki target exist krte h ki nhi 
            // taget > mid and target < mid . AS UK ki ye rotate walaz h toh left mei max hota h isliye hum d3ekhte h ki target low se bada and target mid se bada 

            // Right half is sorted
            else {

                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};
//"Once I know a half is sorted, I simply ask: Does my target belong to this sorted range? If yes, I search there. Otherwise, I search the other half."
/***
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int last = nums.back();

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            // Mid is in left sorted part
            if (nums[mid] > last) {

                if (target > nums[mid]) {
                    low = mid + 1;
                }
                else if (target < nums[0]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }

            // Mid is in right sorted part
            else {

                if (target < nums[mid]) {
                    high = mid - 1;
                }
                else if (target > last) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }

        return -1;
    }
};
*/
