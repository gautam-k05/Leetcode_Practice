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
    void reorderList(ListNode* head) {
        if(head->next == NULL || head->next->next == NULL)
        {

        }
        else
        {
            ListNode *p1,*p2,*p3;
            ListNode *slow = head, *fast = head;
            while(fast->next != NULL && fast->next->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }

            p1 = NULL;
            p2=slow->next;
            p3 = p2->next;
            slow->next = NULL;
            while(p2 != NULL)
            {
                p2->next = p1;
                p1 = p2;
                p2 = p3;
                if(p3!=NULL)
                p3 = p3->next;
            }
            ListNode *back = p1, *front = head;
            
            do{
                p1 = front->next;
                p2 = back->next;
                front->next = back;
                back->next = p1;
                front = p1;
                back = p2;

            }
            while(p2 != NULL);
        }
    }
};