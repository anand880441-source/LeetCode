class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;

        head = reverseList(head);

        ListNode* curr = head;
        int maxVal = curr->val;

        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->val < maxVal) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxVal = curr->val; 
            }
        }

        return reverseList(head);
    }
};
