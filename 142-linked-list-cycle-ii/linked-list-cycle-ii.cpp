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
    ListNode* detectLoop(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(slow == fast) return slow;
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)return nullptr;
        if(!detectLoop(head)) return nullptr;
        ListNode* meetingPoint = detectLoop(head);
        ListNode* temp = head;

        int counter = 0;
        while(temp != meetingPoint){
            temp = temp->next;
            meetingPoint = meetingPoint->next;
        }
        return temp;
    }
};