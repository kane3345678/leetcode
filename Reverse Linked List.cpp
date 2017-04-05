https://leetcode.com/submissions/detail/99126070/
Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode *son, *parent, *cur;

        cur = head;
        parent = NULL;
        while (cur != NULL) {
            son = cur->next;
            cur->next = parent;
            parent = cur;
            cur = son;
        }
        return parent;
    }
};
