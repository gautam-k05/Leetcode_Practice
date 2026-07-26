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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next ==NULL)
            return head;
        ListNode *p1,*p2,*p3;
        p1 = NULL;
        p2=head;
        p3 = p2->next;

        while(p2 != NULL)
        {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p3!=NULL)
            p3 = p3->next;
        }
        return p1;
    }
};