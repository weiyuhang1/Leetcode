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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cur = headA;
        unordered_set<ListNode* > listA;
        while (cur != nullptr) {
            listA.insert(cur);
            cur = cur->next;
        }
        cur = headB;
        while (cur != nullptr) {
            if (listA.find(cur) != listA.end()) return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};