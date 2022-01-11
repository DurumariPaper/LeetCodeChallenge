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
    ListNode* reverse(ListNode* head, int k)
    {
        ListNode* newNode = nullptr;
        ListNode* tail = head;
        
        while(k > 0)
        {
            ListNode* next = tail->next;            
            tail->next = newNode;
            newNode = tail;
            tail = next;
            k--;
        }    
        return newNode; 
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* ptr = head;
        
        while(count < k && ptr != NULL)
        {
            ptr = ptr->next;
            count++;
        }
        
        if(count == k)
        {
            ListNode* reverseNodes = reverse(head,k);
            head->next = reverseKGroup(ptr,k);
            return reverseNodes;
        }
        
        return head;
    }
};