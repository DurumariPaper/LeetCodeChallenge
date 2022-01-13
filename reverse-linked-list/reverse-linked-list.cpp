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
        ListNode* revHead = NULL;
        ListNode* itor = head;
        
        while(itor != NULL)
        {
            ListNode* next = itor->next;
            if(revHead == NULL)
            {
                revHead = itor;
                revHead->next = NULL;
            }
            else
            {
                itor->next = revHead;
                revHead = itor;
            }            
            itor = next;
        }      
        
        
        return revHead;
        
    }
};