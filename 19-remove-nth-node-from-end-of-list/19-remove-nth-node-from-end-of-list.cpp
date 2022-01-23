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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = head;
        int length = 0;
        //find length
        while(first != NULL)
        {
            first = first->next;
            length++;
        }
        
        length -= n;
        
        first = dummy;
        
        //find first
        while(length > 0)
        {
            first = first->next;
            length--;
        }
        
        if(first->next != NULL)
            first->next = first->next->next;
        
        
        return dummy->next;
    }
};