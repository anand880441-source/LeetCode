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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        if(head -> next == nullptr) return head;

        ListNode* i = head;
        ListNode* j = head -> next;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(j != nullptr){
            if(i->val == j->val){
                j = j->next;
            }else{
                if(i->val == i->next->val){
                    i = j;
                    j = j -> next;
                }else{
                    temp -> next = i;
                    i = i -> next;
                    j = j -> next;
                    temp = temp -> next;
                }
            }
        }
        if(i -> next == nullptr){
            temp -> next = i;
            temp = temp -> next;
        }
        temp -> next = nullptr;
        return dummy->next;
    }
};