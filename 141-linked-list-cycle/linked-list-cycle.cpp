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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head -> next == nullptr){
            return false;
        }

        unordered_set<ListNode*> address;
        ListNode* temp = head;

        while(temp != nullptr){
            if(address.count(temp)){
                return true;
            }
            address.insert(temp);
            temp = temp -> next;
        }

        return false;
    }
};