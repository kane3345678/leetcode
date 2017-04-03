https://leetcode.com/problems/add-two-numbers/#/description
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr;
        ListNode *n;
        int carry = 0;
        while (1) {
            int sum = carry;
            
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = 0;
            if (head == nullptr){
                head = new ListNode(sum);
                n = head;
                if (head->val >= 10) {
                    carry = n->val / 10;
                    n->val = n->val % 10;
                }
            }
            else {
                n->next = new ListNode(sum);
                n = n->next;
                if (n->val >= 10) {
                    carry = n->val / 10;
                    n->val = n->val % 10;
                }
            }
          
            if (l1 == NULL && l2 == NULL)
            {
                if (carry > 0) {
                    n->next = new ListNode(carry);
                }
                break;
            }
        }
        return head;
    }
};


