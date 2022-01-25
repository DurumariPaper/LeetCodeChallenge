class Solution {
public:   
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> data;
        for(auto interval : intervals)
        {
            if(data.empty() || data.back()[1] < interval[0])
                data.push_back(interval);
            else
                data.back()[1] = max(data.back()[1], interval[1]);
        }
        
        return data;
    }
};