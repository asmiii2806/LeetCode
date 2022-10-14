//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  //calling function 
  void depthfirstsearch(int V, int currentvertex,vector<bool>&visited, vector<int>&ans,vector<int>adj[])
  {
      
      if(visited[currentvertex]==true)      //if visitedvertex is true then we will return
      {
        return;
      }
      
      visited[currentvertex]=true;          //if not true we wll make it true
      
      ans.emplace_back(currentvertex);      //we will add currentvertex into our ans vector 
      
      vector<int>neighbors=adj[currentvertex];
      
      for(int currentneighbor:neighbors)
      {
        depthfirstsearch(V,currentneighbor,visited,ans, adj);
      }
     return; 
      
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int>ans;
        vector<bool>visited(V+1, false);
        
        
        depthfirstsearch(V,0,visited,ans,adj );
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends