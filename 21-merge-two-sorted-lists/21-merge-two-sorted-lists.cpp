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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* result = nullptr;
        ListNode* resultItor = nullptr;
        
        while(ptr1 != NULL && ptr2 != NULL)
        {
            ListNode* temp = NULL;
            if(ptr1->val <= ptr2->val)
            {
                if(result == nullptr)
                {
                    result = ptr1;
                    resultItor = result;
                }
                else
                {
                    resultItor->next = ptr1;
                    resultItor = ptr1;
                }
                temp = ptr1;
                ptr1 = ptr1->next;
                temp->next = NULL;
            }
            else
            {
                if(result == nullptr)
                {
                    result = ptr2;
                    resultItor = result;
                }
                else
                {
                    resultItor->next = ptr2;
                    resultItor = ptr2;
                }
                temp = ptr2;
                ptr2 = ptr2->next;
                temp->next = NULL;
            }
        }

        
        if(ptr1 != NULL)
        {
            if(result == NULL)
                result = ptr1;
            else
                resultItor->next = ptr1;
        }
        
        if(ptr2 != NULL)
        {            
            if(result == NULL)
                result = ptr2;
            else
            resultItor->next = ptr2;
        }
        
        return result;
    }
};