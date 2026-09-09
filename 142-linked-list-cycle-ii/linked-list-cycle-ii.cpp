/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // if(head == nullptr && head -> next == nullptr){
        //     return head;
        // }

        unordered_set<ListNode*> address;
        ListNode* temp = head;

        while(temp != nullptr){
            if(address.count(temp)){
                return temp;
            }
            address.insert(temp);
            temp = temp -> next;
        }

        return NULL;
    }
};