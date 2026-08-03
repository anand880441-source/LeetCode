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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = nullptr;
        ListNode* curr = head;
        ListNode* cNext = nullptr;

        while(curr != nullptr){
            cNext = curr->next;
            curr->next = temp;
            temp = curr;
            curr = cNext;
        }

        return temp;
    }
};