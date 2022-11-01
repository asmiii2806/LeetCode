//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int row,int col,int row0,int col0,vector<vector<int>>&grid,vector<vector<int>>&visited,vector<pair<int,int>>&vec)
    {
    int m=grid.size();
     int n=grid[0].size();
        
        
        if(row<0 ||  row>=m  || col<0  || col>=n ||  visited[row][col]==1 || grid[row][col]==0)
        {
            return;
        }
        visited[row][col]=1;
        vec.push_back({row-row0, col-col0});

        dfs(row + 1, col,row0,col0,  grid,visited,vec);
        dfs(row, col + 1, row0,col0,grid,visited,vec);
        dfs(row - 1, col,row0,col0 , grid,visited,vec);
        dfs(row, col - 1, row0,col0, grid,visited,vec);
    return;    
    }
    
// MAIN FUNCTION
int countDistinctIslands(vector<vector<int>>& grid)
    {
         int m=grid.size();
     int n=grid[0].size();
     vector<vector<int>>visited(m,vector<int>(n,0));
     set<vector<pair<int,int>>>st;
        
        for(int i=0; i<m;i++)
        {
            for(int j=0; j<n;j++)
            {
                
                if(!visited[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>vec;
                    
                    dfs(i,j,i,j,grid,visited,vec);
                    st.insert(vec);
                }
            }
        }
                  
    return st.size();    // code here
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends