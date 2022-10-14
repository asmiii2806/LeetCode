class Solution {
public:
    
    void dfs(int currentvertex,vector<vector<int>>&graph, vector<bool>&visited,int n)
    {
        
      if(visited[currentvertex]==true)      //if visitedvertex is true then we will return
      {
        return;
      }
      
      visited[currentvertex]=true;          //if not true we wll make it true
      
      
      vector<int>neighbors=graph[currentvertex];
      
      for(int i=0; i<n; i++)
      {
          if(neighbors[i]==1)
             dfs(i,graph,visited,n);
      }
     return; 
    }
        
         
        
    
    int findCircleNum(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        int ans=0;        
        vector<bool>visited(n);
        for(int currentcity=0; currentcity<n; currentcity++)
        {
            if(visited[currentcity]==false)
            {
                dfs(currentcity, graph, visited,n);
                ans+=1;

            }
        }
        return ans;
    }
};