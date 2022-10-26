class Solution {
public:
    
    int dfs(int  row,int col,int m,int n,vector<vector<int>>&grid  )
    {
        if(row<0 ||  row>=m || col<0 || col>=n || grid[row][col]==0)
        {
            return 0; 
        }
          grid[row][col] =0;
        int a=dfs(row + 1, col,m,n,  grid);
        int b=dfs(row, col + 1, m,n,grid);
        int c=dfs(row - 1, col, m,n, grid);
        int d=dfs(row, col - 1, m,n, grid);
    return(1+a+b+c+d);    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int m=grid.size();
     int n=grid[0].size();
        
        int maxarea=0; 
        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n;j++)
            {
                
                if(grid[i][j]==1)
                {
                     maxarea=max(maxarea,dfs(i,j,m,n,grid));
                    
                }
            }
        }
        return maxarea;   
    }
};