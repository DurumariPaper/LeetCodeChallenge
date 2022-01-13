/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL;
        unordered_map<Node*, Node*> link;
        
        Node* itor = head;
        Node* prev = NULL;
        while(itor != NULL)
        {               
            Node* newNode = new Node(itor->val);
            if(prev != NULL)
                prev->next = newNode;            
            if(newHead == NULL)
                newHead = newNode;
            
            link[itor] = newNode;
            prev = newNode;
            itor = itor->next;
        }
        
        itor = head;
        while(itor != NULL)
        {
            Node* copiedNode = link[itor];
            copiedNode->random = link[itor->random];
            itor = itor->next;
        }
        
        return newHead;
    }
};