class MyLinkedList {
    int val;
    MyLinkedList* next;
public:
    MyLinkedList() : val(0), next(NULL){
        
    }
    MyLinkedList(int v) : val(v), next(NULL){
        
    }
    
    int get(int index) {
        if(next == NULL)
            return -1;
        
        MyLinkedList* itor = next;
        for(int i = 0; i < index; i++)
        {
            if(itor->next == NULL)
                return -1;
            itor = itor->next;
        }  
        
        return itor->val;
    }
    
    void addAtHead(int val) {
        MyLinkedList* node = new MyLinkedList(val);
        if(next != NULL)
        {            
            MyLinkedList* temp = next;
            node->next = temp;
        }        
        next = node;
        
    }
    
    void addAtTail(int val) {
        MyLinkedList* node = new MyLinkedList(val);
        MyLinkedList* itor = next;
        if(itor == NULL)
            next = node;
        else
        {
            while(itor->next != NULL)
            {
                itor = itor->next;
            }
            itor->next = node;            
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0)
        {
            addAtHead(val);
            return;
        }
        
        if(next == NULL)
            return;
        
        MyLinkedList* itor = next;        
        for(int i = 0; i < index - 1 ; i++)
        {
            if(itor->next == NULL)
                return;
            itor = itor->next;
        }
        MyLinkedList* node = new MyLinkedList(val);
        MyLinkedList* temp = itor->next;
        node->next = temp;
        itor->next = node;
    }
    
    void deleteAtIndex(int index) {
        if(next == NULL)
            return;
        if(index == 0)
        {
            MyLinkedList* temp = next;
            next = next->next;
            delete temp;
            return;
        }
        
        
        MyLinkedList* itor = next;  
        MyLinkedList* prev = this;        
        for(int i = 0; i < index ; i++)
        {

            prev = itor;
            if(itor->next == NULL)
                return;
            itor = itor->next;
        }
        
        prev->next = itor->next;
        delete itor;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */