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

/*
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // maintain an unchanging reference to node ahead of the return node.
        ListNode prehead = new ListNode(-1);

        ListNode prev = prehead;
        while (l1 != null && l2 != null) {
            if (l1.val <= l2.val) {
                prev.next = l1;
                l1 = l1.next;
            } else {
                prev.next = l2;
                l2 = l2.next;
            }
            prev = prev.next;
        }

        // At least one of l1 and l2 can still have nodes at this point, so connect
        // the non-null list to the end of the merged list.
        prev.next = l1 == null ? l2 : l1;

        return prehead.next;
    }
}
*/

/*
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        else if (l2 == null) {
            return l1;
        }
        else if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }
        else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }

    }
}
*/