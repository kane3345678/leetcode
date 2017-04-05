https://leetcode.com/submissions/detail/99133510/
Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *i, *j;
        if (!head)
            return head;
        i = head;
        j = i->next;
        while(i != NULL && j != NULL) {
            bool found = false;
            while (j != NULL) {
                if (j->val != i->val) {
                    found = true;
                    break;
                }
                j = j->next;
                
            }
            if (found) {
                i->next = j;
                i = j;
                j = j->next;
            }
        }
        i->next = j;
        return head;
    }
};
