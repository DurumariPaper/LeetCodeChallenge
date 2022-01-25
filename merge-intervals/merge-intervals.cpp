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

//interval을 일단 소팅을 하여서 앞에 있는 숫자로 정렬을 시킨다.
//그리고 interval이 발생하는지 순회를 한다.
//만약 현재 interval이 발생한다면 그냥 바로 값을 추가한다.
//interval이 발생하지 않는 경우라면 뒤의 값만 갱신하고 정리를 한다.