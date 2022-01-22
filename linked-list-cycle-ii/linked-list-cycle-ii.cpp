/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    unordered_map<ListNode*, int> visited;
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* itor = head;
        int index = 0;
        while(itor != NULL)
        {
            if(visited.count(itor) == 0)
            {
                visited[itor] = index;
                itor = itor->next;
            }
            else
                return itor;
        }
        
        return NULL;
    }
};