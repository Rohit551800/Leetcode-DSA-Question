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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return nullptr;
        ListNode* fastp = head;
        ListNode* slowp = head;
        while(fastp->next != nullptr && fastp->next->next != nullptr){
            fastp = fastp->next->next;
            slowp = slowp->next;
        }
        while(fastp->next != nullptr){
            fastp = fastp->next;
            slowp = slowp->next;
        }
        ListNode* temp = head;
        while(temp->next != slowp){
            temp = temp->next;
        }
        temp->next = slowp->next;
        delete slowp;
        return head;
    }
};