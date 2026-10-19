/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return slow;
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {

        ListNode* fast = hasCycle(head);
        if(!fast) return nullptr;
        ListNode* slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};