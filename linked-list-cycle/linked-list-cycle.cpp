/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    unordered_map<ListNode*, bool> visited;
public:
    bool hasCycle(ListNode *head) {
        ListNode* itor = head;
        while(itor != NULL)
        {
            if(visited.count(itor) == 0)
            {
                visited[itor] = true;
                itor = itor->next;
            }
            else
                return true;
        }
        
        return false;
    }
};