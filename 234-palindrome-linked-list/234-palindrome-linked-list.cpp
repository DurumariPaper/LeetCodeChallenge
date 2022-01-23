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
    ListNode* endOfFistHalf(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;            
            curr = next;
        }
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        if(head->next == NULL)
            return true;
        
        
        ListNode* firstHalfEnd =  endOfFistHalf(head);
        ListNode* secondHalfStart = reverseList(firstHalfEnd->next);
        
        ListNode* p1 = head;
        ListNode* p2 = secondHalfStart;
        bool result = true;
        
        while(result && p2 != NULL)
        {
            if(p1->val != p2->val)
                result = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        
        firstHalfEnd->next = reverseList(secondHalfStart);        
                
        return result;
        
    }
};