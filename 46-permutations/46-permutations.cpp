class Solution {
public:
    int size;
    vector<vector<int>> result;
    unordered_map <int, int> checker;
    void permute(vector<int>& nums, int index, vector<int>& vec)
    {
        bool check = true;
        for(int i = 0; i < size; i++)
        {
            if(checker[i] == 0)
            {
                check = false;
                break;
            }   
        }
        if(check)
        {
            result.push_back(vec);
            return;
        }
        
        for(int i = 0; i < size; i++)
        {
            if(checker[i] != 0)
                continue;
            
            vec.push_back(nums[i]);
            checker[i]++;
            permute(nums, i + 1, vec);
            vec.pop_back();
            checker[i]--;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        size = nums.size();
        vector<int> vec;
        permute(nums,0, vec);
        
        return result;
    }
};