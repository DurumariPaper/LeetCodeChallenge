class LRUCache {
public:
    list<int> key_list; 
    unordered_map<int, pair<list<int>::iterator, int>> key_tolist; 
    int i_size; 
    int num; 
    LRUCache(int capacity) {
        
        i_size = capacity; 
        num =0; 
        
    }
    
    int get(int key) {
        auto it = key_tolist.find(key);
        if(it!=key_tolist.end())
        {
            //  we have key and update to latest. 
            int value = (*it).second.second; 
            key_list.erase((*it).second.first); 
            key_list.push_front(key); 
            key_tolist[key] = make_pair(key_list.begin(), value) ;   
            return value; 
        }
        else // can't find. 
        {
            return -1; 
        }
        
    }
    
    void put(int key, int value) { 
        auto it = key_tolist.find(key);         
        if(it!=key_tolist.end()) // we found this value. just update. 
        {
            // remove the previous. then update to latest. 

            key_list.erase((*it).second.first); 
        }
        else if(num<i_size)
        {
            num++; 
        }
        else
        {
            auto it = key_list.back(); 
            key_tolist.erase(it); // 
            key_list.pop_back(); 
        }    
        
        key_list.push_front(key); 
        key_tolist[key] = make_pair(key_list.begin(),value);         
    }    
};