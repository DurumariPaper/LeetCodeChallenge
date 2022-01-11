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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultList;
        ListNode* resultIter;
        
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        int cache = 0;
        
        //동일 사이즈
        while(1)
        {            
            int result = iter1->val + iter2->val + cache;
            cache = 0;
            if(result > 9)
            {
                result -= 10;
                ++cache;
            }
            iter1->val = iter2->val = result;
            
            if(iter1->next == nullptr || iter2->next == nullptr)
                break;
            
            iter1 = iter1->next;
            iter2 = iter2->next;           
        }
        
        if(iter1->next != nullptr)
        {
            resultList = l1;
            resultIter = iter1;
        }
        else
        {
            resultList = l2;
            resultIter = iter2;
        }
                
        while(resultIter->next != nullptr)
        {
            resultIter = resultIter->next;
            resultIter->val += cache;
            cache = 0;
            if(resultIter->val > 9)
            {
                resultIter->val -= 10;
                ++cache;
            }
        }
        
        if(cache == 1)
        {
            resultIter->next = new ListNode(1);
        }
        
        return resultList;
    }
};