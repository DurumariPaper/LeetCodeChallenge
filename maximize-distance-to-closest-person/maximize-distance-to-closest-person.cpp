class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int index = -1;
        int current = 0;
        int maxDist = 0;
        for(int i = 0; i < seats.size(); i++)
        {
            if(seats[i] == 1)
            {
                if(index == -1)
                {
                    maxDist = max(maxDist, i - index - 1);
                    index = i;
                }
                else
                {
                    maxDist = max(maxDist, (int)((i - index) / 2) );
                    index = i;
                }
            }
        }
        
        maxDist = max(maxDist, ((int)seats.size() - 1) - index);
        return maxDist;
    }
};