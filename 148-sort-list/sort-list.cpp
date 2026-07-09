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
    ListNode* findMiddleNode(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge2SortedList(ListNode* head1 , ListNode* head2){
        if(head1 == nullptr) return head2;
        if(head2 == nullptr) return head1;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp3 = dummyNode;
        while(head1 && head2){
            if(head1->val <= head2->val){
                temp3->next = head1;
                head1 = head1->next;
                temp3 = temp3->next;
            }
            else{
                temp3->next = head2;
                head2 = head2->next;
                temp3 = temp3->next;
            }
        }
        if(head1) temp3->next = head1;
        else temp3->next = head2;
        return dummyNode->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* middle = findMiddleNode(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return merge2SortedList(left , right);
    }
};