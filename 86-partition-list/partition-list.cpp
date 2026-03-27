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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);

        ListNode* temp1 = head;
        ListNode* temp2 = left;
        ListNode* temp3 = right;
        while(temp1 != nullptr){
            if(temp1->val >= x){
                temp3->next = temp1;
                temp3 = temp3->next;
            }
            else{
                temp2->next = temp1;
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        temp3->next = nullptr;
        temp2->next = right->next;
        return left->next;
    }
};