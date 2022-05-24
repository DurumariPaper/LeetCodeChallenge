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
        ListNode* revHead = new ListNode();
        
        ListNode* iter = head;
        while(iter != NULL)
        {
            ListNode* next = iter->next;
            iter->next = revHead->next;
            revHead->next = iter;
            iter = next;            
        }
        
        return revHead->next;
    }
};