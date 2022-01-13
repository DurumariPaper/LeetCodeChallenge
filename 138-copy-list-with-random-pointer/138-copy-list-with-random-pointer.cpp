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
    unordered_map<Node*, Node*> link;
    
    Node* copyNode(Node* node)
    {
        if(node == NULL)
            return NULL;
        if(link.count(node) == 0)
        {
            Node* newNode = new Node(node->val);
            link[node] = newNode;
            return newNode;    
        }
        
        return link[node];
    }
    
    Node* copyRandomList(Node* head) {
        Node* newHead = NULL;        
        Node* itor = head;
        
        while(itor != NULL)
        {
            Node* newNode = copyNode(itor);
            newNode->next = copyNode(itor->next);
            newNode->random = copyNode(itor->random);
            
            if(newHead == NULL)
                newHead = newNode;
            
            itor = itor->next;
        }
        
        return newHead;
    }
};

/*
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
};*/

/*
public class Solution {
  // Visited dictionary to hold old node reference as "key" and new node reference as the "value"
  HashMap<Node, Node> visited = new HashMap<Node, Node>();

  public Node getClonedNode(Node node) {
    // If the node exists then
    if (node != null) {
      // Check if the node is in the visited dictionary
      if (this.visited.containsKey(node)) {
        // If its in the visited dictionary then return the new node reference from the dictionary
        return this.visited.get(node);
      } else {
        // Otherwise create a new node, add to the dictionary and return it
        this.visited.put(node, new Node(node.val, null, null));
        return this.visited.get(node);
      }
    }
    return null;
  }

  public Node copyRandomList(Node head) {

    if (head == null) {
      return null;
    }

    Node oldNode = head;

    // Creating the new head node.
    Node newNode = new Node(oldNode.val);
    this.visited.put(oldNode, newNode);

    // Iterate on the linked list until all nodes are cloned.
    while (oldNode != null) {
      // Get the clones of the nodes referenced by random and next pointers.
      newNode.random = this.getClonedNode(oldNode.random);
      newNode.next = this.getClonedNode(oldNode.next);

      // Move one step ahead in the linked list.
      oldNode = oldNode.next;
      newNode = newNode.next;
    }
    return this.visited.get(head);
  }
}
*/