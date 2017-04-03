Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *h = head->next;
        ListNode *i = head;
        ListNode *tmp;
        while(1) {
            tmp = i->next;
          //  cout<<i->val<<"  "<<tmp->val<<endl;
            if (i->next != NULL) {
                i->next = i->next->next;
                if(i->next != NULL)
                    i = i->next;
                else
                    break;
            }

            if (tmp->next != NULL) {
                tmp->next = tmp->next->next;
                if(tmp->next != NULL)
                    tmp = tmp->next;
                else
                    break;
            }

            if (i == NULL || tmp == NULL)
                break;
        }
        i->next = h;
        return head;
    }
};