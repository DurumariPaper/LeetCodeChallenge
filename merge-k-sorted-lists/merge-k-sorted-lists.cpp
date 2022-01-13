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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for( ListNode* node : lists)
        {
            ListNode* itor = node;
            while(itor != NULL)
            {
                ListNode* temp = itor;
                pq.push(itor->val);
                itor = itor->next;
            }
        }
        
        ListNode* head = new ListNode();
        ListNode* itor = head;
        
        while(!pq.empty())
        {
            itor->next = new ListNode(pq.top());
            itor = itor->next;
            pq.pop();
        }
        
        return head->next;
        
        
    }
};

/*

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int, vector<int>, greater<int>>qt ;
        
        for(auto&k:lists)
        {
            ListNode* tmp = k ;
            while(tmp!=NULL)
            {
                qt.push(tmp->val);
                tmp=tmp->next ;
            }
        }
        

        ListNode* ans = new ListNode(0) ;
        ListNode* temp = ans ;
        
        while( !qt.empty() ) 
        {
            ans->next = new ListNode(qt.top());
            ans=ans->next ;
            //cout<<qt.top()<<endl;
            qt.pop();
        }
        
        return temp->next ;
        
    }
*/

/*
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
        // sort( mergedList.begin( ), mergedList.end( ), [ ]( const ListNode* lhs, const ListNode* rhs )
        // {
        //    return lhs->val < rhs->val;
        // });
        
        for(int i = 0; i < mergedList.size() - 1; i++)
        {
            mergedList[i]->next = mergedList[i+1];
        }
        
        return mergedList[0];
        
    }
};*/