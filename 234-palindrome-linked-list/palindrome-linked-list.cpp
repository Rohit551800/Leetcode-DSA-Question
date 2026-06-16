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
// ListNode* reverseSLL(ListNode* head){
//     if(head == nullptr || head->next == nullptr) return head;
//     ListNode* newHead = reverseSLL(head->next);
//     ListNode* front = head->next;
//     front->next = head;
//     head->next = nullptr;
//     return newHead;
// }
    bool isPalindrome(ListNode* head) {
//     if(head == nullptr || head->next == nullptr)return true;
//     ListNode* slowp = head;
//     ListNode* fastp = head;
//     while(fastp->next != nullptr && fastp->next->next != nullptr){
//         fastp = fastp->next->next;
//         slowp = slowp->next;
//     }
//     ListNode* newHead =  reverseSLL(slowp->next);
//     ListNode* first = head;
//     ListNode* second = newHead;
//     while(second != nullptr){
//         if(first->val != second->val){
//             reverseSLL(newHead);
//             return false;
//         }
//         first = first->next;
//         second = second->next;
//     }
//     reverseSLL(newHead);
//     return true;



    //Bruteforce solution using array

        vector<int>arr;
        for(ListNode* temp = head;temp != nullptr ;temp = temp->next){
            arr.push_back(temp->val);
        }
        int left = 0 , right = arr.size()-1;

        while(left <= right){
            if(arr[left] != arr[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};