// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {
//         for (int i = 0; i < nums.size(); i++) {
//             if (head != nullptr && head->val == nums[i]) {
//                 head = head->next;
//             }
//             ListNode* temp = head;

//             while (temp != nullptr && temp->next != nullptr) {
//                 if(temp->next->val == nums[i]){
//                     temp -> next = temp -> next -> next;
//                     temp = head;
//                 }
//                 else{
//                     temp = temp->next;
//                 }
//             }
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> s1(nums.begin(),nums.end());

        while(head != nullptr && s1.count(head->val)) {
            head = head->next;
        }
        ListNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            if (s1.count(temp->next->val)) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};