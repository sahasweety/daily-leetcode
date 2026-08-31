/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int first = -1;
        int last = -1;

        int minDistance = INT_MAX;

        int index = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != NULL) {

            ListNode* next = curr->next;

            // Check if curr is a critical point
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                // First critical point
                if (first == -1) {
                    first = index;
                }
                else {
                    // Distance from previous critical point
                    minDistance = min(minDistance, index - last);
                }

                // Update last critical point
                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Less than 2 critical points
        if (first == last) {
            return {-1, -1};
        }

        int maxDistance = last - first;

        return {minDistance, maxDistance};
    }
};