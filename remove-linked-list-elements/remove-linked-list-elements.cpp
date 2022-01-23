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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
                
        ListNode* itor = dummy;
        while(itor->next != NULL)
        {
            ListNode* temp = itor->next;
            if(temp->val == val)
            {
                itor->next = temp->next;
                delete temp;
                continue;
            }
            
            itor = itor->next;
        }
        return dummy->next;
    }
};