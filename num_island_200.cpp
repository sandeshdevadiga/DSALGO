class Solution {
public:
    void DFS(std::vector<std::vector<bool>>& isvisited,vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || i>=grid.size() ||  j<0 || j>=grid[0].size() || isvisited[i][j] == true || grid[i][j]=='0')
        {
            return;
        }
        isvisited[i][j]=true;
        DFS(isvisited,grid,i,j+1);
        DFS(isvisited,grid,i+1,j);
        DFS(isvisited,grid,i-1,j);
        DFS(isvisited,grid,i,j-1);

    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        
        int count=0;
        std::vector<std::vector<bool>> isvisited(grid.size(),std::vector<bool>(grid[0].size(),false));
        if(grid.size()==0 )
        {
            return 0;
        }
        for(int i=0; i<grid.size();i++)
        {
            for(int j=0; j<grid[0].size();j++)
            {
                if( !isvisited[i][j] && grid[i][j]=='1')
                {
                   DFS(isvisited,grid,i,j);
                    count++;            
                }
            }
        }
        return count;
    }
};