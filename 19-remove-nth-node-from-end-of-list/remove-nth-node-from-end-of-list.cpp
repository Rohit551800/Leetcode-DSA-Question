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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    // if(head == nullptr)return nullptr;
    // ListNode* fastp = head;
    // ListNode* slowp = head;
    // for(int i=0;i<n;i++){
    //     fastp = fastp->next;
    // }
    // if(fastp == nullptr){
    //     ListNode* temp = head;
    //     head = temp->next;
    //     return head;
    // }
    // while(fastp->next != nullptr){
    //     slowp = slowp->next;
    //     fastp = fastp->next;
    // }
    // slowp->next = slowp->next->next;
    // return head;


        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* temp1 = head;
        int length = 0;
        while(temp1){
            temp1 = temp1->next;
            length += 1;
        }
        if(n == length) {
        ListNode* newHead = head->next;
        return newHead;
        }
        if(n > length) return head;
        temp1 = head;
        int finalP = length - n;
        for(int i=1;i<finalP;i++){
            temp1 = temp1->next;
        }

        temp1->next = temp1->next->next;
        return head;
    }
};