class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Adjacency list
        vector<int> inDegree(numCourses, 0); // In-degree array
        vector<int> result; // Stores the topological order
        queue<int> q; // Queue for BFS

        // Build graph and calculate in-degrees
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
        }

        // Enqueue nodes with in-degree 0
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the nodes
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);

            // Reduce the in-degree of neighbors
            for (int neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check if topological sort is possible
        if (result.size() == numCourses) {
            return result; // Valid order
        }
        return {}; // Cycle detected
    }
};

/*

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        std::vector<int> oder(numCourses,0);
        std::vector<int> ret;
        std::queue<int> q;

        for(auto& elem: prerequisites)
        {
            oder[elem[0]]++;
        }
     
        for(int i=0; i<oder.size();i++)
        { 
            if(oder[i]==0)
            {
                q.push(i);
            }
        }

       while(!q.empty())
       {
            int id=q.front();
            q.pop();
            ret.push_back(id);

           for(auto& elem: prerequisites)
           {
                if (elem[1] == id)
                {
                    oder[elem[0]]--;
                    if(oder[elem[0]]==0)
                    {
                        q.push(elem[0]);
                    }
                }
            
           }
       }

   
        if(ret.size()==numCourses)
        {
            return ret;

        }
        else{
            return {};
        }
    }
};*/