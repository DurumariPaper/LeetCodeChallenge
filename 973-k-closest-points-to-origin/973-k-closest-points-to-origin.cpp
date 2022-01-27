class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int,int> maps;
        
        int index = 0;
        for(vector<int> point : points)
        {
            maps[index++] = point[0]*point[0] + point[1]*point[1];
        }
        
        vector<pair<int,int>> datas(maps.begin(), maps.end());
        
        sort(datas.begin(), datas.end(), [&](pair<int,int>& a, pair<int,int>& b)
             {
                return a.second < b.second; 
             });
        
        vector<vector<int>> result;
        for(int i = 0; i < k; i++)
        {
            result.push_back(points[datas[i].first]);
        }
        return result;
    }
};