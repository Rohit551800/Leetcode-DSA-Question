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
        if(!head || left == right) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;

        int count = 1;
        while(curr && count < left){
            prev = curr;
            curr = curr->next;
            count++;
        }

        ListNode* before  = prev;
        ListNode* tail  = curr;

        while(curr && count <= right){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            count++;
        }

        if(before){
            before->next = prev;
        }
        else{
            head = prev;
        }

        tail->next = curr;
        return head;
    }
};