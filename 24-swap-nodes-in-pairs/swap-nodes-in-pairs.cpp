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
    ListNode* swapPairs(ListNode* head) {
        // if(!head || !head->next) return head;
        // ListNode* temp1 = head;
        // ListNode* temp2 = head->next;;

        // while(temp1 && temp2){
        //     int x = temp1->val;
        //     temp1->val = temp2->val;
        //     temp2->val = x;
            
        //     temp1 = temp2->next;
        //     if(temp1){
        //         temp2 = temp1->next;
        //     }
        //     else{
        //         temp2 = nullptr;
        //     }
        // }
        // return head;

        //Need to swap the nodes
        if(!head || !head->next) return head;
        ListNode* dummyN = new ListNode(-1);
        ListNode* prev = dummyN;
        dummyN->next = head;

        while(prev->next && prev->next->next){
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }
        return dummyN->next;
    }
};