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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right)
        return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        for(int i = 1; i<left;i++)
        prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* prevNode = NULL;
        ListNode* next = NULL;

        for(int i = 0; i<right-left+1;i++){
            next = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr= next;
        }
        prev->next->next=curr;
        prev->next=prevNode;

        return dummy.next;
        
    }
};
/**head insertion 
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left==right)
        return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        for(int i = 1; i<left;i++)
        prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* prevNode = NULL;  /remove this
        ListNode* next = NULL;      /remove this 

        for(int i = 0; i<right-left;i++){
            ListNode* temp= curr->next;
            curr->next = temp->next;
            temp->next = prev->next
            prev->next= temp;
        }
        //remove prev->next->next=curr;
        // remove prev->next=prevNode;

        return dummy.next;
        
    }
};
*/