class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;
        
        for(auto interval : intervals)
        {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0;
        int j = 0;
        int max = 0;
        int n = intervals.size();
        while(i < n)
        {
            max = std::max(max, i - j);
            if(start[i] < end[j])
                i++;
            else if(start[i] == end[j])
            {
                i++; j++;
            }
            else
                j++;               
        }
        
        
        max = std::max(max, i - j);
        return max;
    }
};
