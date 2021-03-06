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
        ListNode* prev = new ListNode(200);
        ListNode* cur = head;
        ListNode* temp;
        while (cur != nullptr) {
            if (cur->val == prev->val) {
                prev->next = cur->next;
                temp = cur;
                cur = cur->next;
                delete temp;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};