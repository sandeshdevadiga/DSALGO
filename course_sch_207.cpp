class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        using Oder =std::vector<int> ;
        using Graph= std::vector<vector<int>> ;
        Oder O(numCourses,0);
        std::vector<int> r;
        Graph g(numCourses);
        std::queue<int> q;
     
        for(auto& e :  prerequisites)
        {
            g[e[1]].push_back(e[0]);
            O[e[0]]++;
        }

        for(int i=0; i<O.size();i++)
        {
            if(O[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int temp=q.front();
            r.push_back(temp);

            q.pop();
            for(auto& e : g[temp])
            { 
                O[e]--;
                if(O[e]==0)
                {
                    q.push(e);
                }
                
            }

        }
        if(r.size()==numCourses)
        {
            return true;
        }

        return false;
    }
};