class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashmap;
        for(int num : nums)
        {
            hashmap[num]++;
        }
        
        
        auto iter = hashmap.begin();
        
        auto comp = [&hashmap](int n1, int n2) { return hashmap[n1] > hashmap[n2]; };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
       
        for(auto p : hashmap)
        {
            heap.push(p.first);
            if(heap.size() > k) heap.pop();
        }
        
        
        vector<int> result(k);
        for(int i = k - 1; i >= 0; i--)
        {
            result[i] = heap.top();
            heap.pop();
        }
        return result;
    }
};