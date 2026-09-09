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
    bool isPalindrome(ListNode* head) {
        ListNode* address = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {
            ListNode* newNode = new ListNode();
            newNode -> next = address;
            address = newNode;
            newNode -> val = temp -> val;
            temp = temp -> next;
        }

        ListNode* temp1 = address;
        temp = head;

        while(temp1 -> next!= nullptr){
            if(temp1 -> val != temp -> val){
                return false;
            }
            temp1 = temp1 -> next;
            temp = temp -> next;
        }

        return true;
    }
};