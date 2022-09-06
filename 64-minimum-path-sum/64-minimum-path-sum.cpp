class Solution {
public:
    int mincost(int currentrow, int currentcol, int m, int n,vector<vector<int>>& grid,vector<vector<int>>& t)
    {
        if(currentrow==m-1 && currentcol==n-1)
        {
            return grid[currentrow][currentcol];
            
        }
        
        if(currentrow>=m || currentcol>=n)
        {
            return 100001;
        }
         if( t[currentrow][currentcol]!=-1)
            return t[currentrow][currentcol];
        
        int rightmove=grid[currentrow][currentcol]+mincost(currentrow, currentcol+1, m, n, grid,t);
        int downmove=grid[currentrow][currentcol]+mincost(currentrow+1, currentcol, m, n,grid,t);
        
        t[currentrow][currentcol]=min(downmove, rightmove);
        return min(downmove, rightmove);
    }
        
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>t(m, vector<int>(n, -1));
        return mincost(0,0,m,n,grid,t);
        
        
    }
};