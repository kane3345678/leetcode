Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector <ListNode*> a;
        while (1)
        {
            a.push_back(head);
            if (head->next == NULL)
                break;
            head = head->next;
        }
        int k = a.size();
        if (n > k)
            return NULL;
        else if (n == a.size()){
            if (a.size() == 1)
                return NULL;
            return a[1];
        }
        else if (n == 1){
            a[k-2]->next = NULL;
            return a[0];
        }
        
        else {
            (a[k - n - 1])->next = a[k - n + 1];
            return a[0];
        }
    }
};

