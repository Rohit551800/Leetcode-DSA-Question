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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //Find mid
        if(!head || !head->next) return ;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        
        head2 = reverseLL(head2);

        ListNode* temp1 = head;
        ListNode* temp2 = head2;

        while(temp1 && temp2){
            ListNode* nextNode1 = temp1->next;
            ListNode* nextNode2 = temp2->next;

            temp1->next = temp2;
            temp2->next = nextNode1;

            temp1 = nextNode1;
            temp2 = nextNode2; 
        }
    }
};