class Solution {
public:
       // unordered_map<string, int>mp;
    int totalways(vector<vector<int>>& t,int currentrow, int currentcol, int m, int n, vector<vector<int>>& obstacleGrid)
    {
        if(currentrow==m-1 && currentcol==n-1 && obstacleGrid[currentrow][currentcol]!=1 )
        {
            return 1;
        }
        
        if(currentrow>=m || currentcol>=n )
            return 0;
        
           if (obstacleGrid[currentrow][currentcol]==1)
        {
            return 0;
        }
        
        if( t[currentrow][currentcol]!=-1)
            return t[currentrow][currentcol];
        
        int rightmove=totalways(t,currentrow, currentcol+1, m, n,obstacleGrid );
        int downmove=totalways(t,currentrow+1, currentcol, m,n,obstacleGrid);
        
        t[currentrow][currentcol]=rightmove+downmove;
        
       return  rightmove+downmove;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
         vector<vector<int>> t(m, vector<int>(n, -1));

        return totalways(t,0,0, m,n, obstacleGrid);

    }
};