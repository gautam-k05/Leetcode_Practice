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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0)
            return NULL;

        int smallest = 10000;
        int min_index = k+1;
        for(int i = 0; i < k; i++)
        {
            if(lists[i] != NULL && lists[i]->val < smallest )
            {    
                min_index = i;
                smallest = lists[i]->val;
            }
        }
        if(min_index == k+1)
            return NULL;
        
        ListNode* head = lists[min_index];
        lists[min_index] = lists[min_index]->next;
        ListNode* current = head;

        bool all_null = false;

        while(all_null == false)
        {
            all_null = true;
            smallest = 10000;
            for(int i = 0; i<k;i++)
            {
                if(lists[i] != NULL && lists[i]->val < smallest )
                {    
                    min_index = i;
                    smallest = lists[i]->val;
                    all_null = false;
                }
                
            }
            if(all_null == false)
            {
                current->next = lists[min_index];
                lists[min_index] = lists[min_index]->next;
                current = current->next;
            }
        }
        return head;

        
    }
};

//time complexity is high, ill try again