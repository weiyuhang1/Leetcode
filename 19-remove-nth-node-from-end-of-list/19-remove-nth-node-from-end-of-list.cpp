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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* cur = head;
        while (cur) {
            sz++;
            cur = cur->next;
        }
        ListNode* pre = nullptr;
        cur = head;
        for (int i = 0; i < sz - n; i++) {
            pre = cur;
            cur = cur->next;
        }
        if (pre == nullptr) {
            head = cur->next;
        } else {
            pre->next = cur->next;
        }
        delete cur;
        return head;
    }
};