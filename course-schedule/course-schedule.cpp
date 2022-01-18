class Solution {
public:
     bool canFinish(int numCourses, vector<vector<int>>& p) {
        vector<int>adj[numCourses]; vector<int>in(numCourses,0);
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
            in[p[i][0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
           if(in[i]==0) q.push(i);
        
        int n{0};
        while(!q.empty()){
            auto t= q.front(); q.pop();
            n++;
            for(auto it: adj[t]){
                if(--in[it]==0) q.push(it);
            }
        }
        if(n==numCourses) return 1;
        else return 0;
    }
};