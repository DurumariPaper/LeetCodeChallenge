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

/*
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> v;
        ListNode *temp;
            
        for(auto &it: lists){
            temp = it;
            while(temp){
                v.push_back(temp->val);
                temp = temp->next;
            }
            
        }
        
        ListNode *ans = new ListNode(0);
        temp = ans;
        
        sort(v.begin(), v.end());
        int n = v.size(), i = 0;
        
        while(i < n){
            ans->next = new ListNode(v[i]);
            ans = ans->next;
            i++;
        }
        
        return temp->next;
        
    }
};
*/
/*
class Solution {
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, ListNode*> pq;
        
    }
}*/


class Solution {
public:
    static bool compare(const ListNode* val1,const ListNode* val2)
    {
        return val1->val < val2->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> mergedList;
        for( ListNode* node : lists)
        {
            ListNode* itor = node;
            while(itor != NULL)
            {
                ListNode* temp = itor;
                mergedList.push_back(itor);
                itor = itor->next;
                temp->next = NULL;
            }
        }
        
        if(mergedList.size() == 0)
            return NULL;
        
        sort(mergedList.begin(), mergedList.end(), compare);       
        /*sort( mergedList.begin( ), mergedList.end( ), [ ]( const ListNode* lhs, const ListNode* rhs )
        {
           return lhs->val < rhs->val;
        });*/
        
        for(int i = 0; i < mergedList.size() - 1; i++)
        {
            mergedList[i]->next = mergedList[i+1];
        }
        
        return mergedList[0];
        
    }
};