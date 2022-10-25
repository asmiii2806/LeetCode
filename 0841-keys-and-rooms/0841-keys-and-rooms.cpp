class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();   
        queue<int>q;
        q.push(0);
        vector<bool>visited(n,false);
        
        visited[0]=true;
        
        while(!q.empty())
        {
            int room=q.front();
            q.pop();
            
            for(auto roomkey: rooms[room])
            {
                if(!visited[roomkey])
                {
                    visited[roomkey]=true;
                    q.push(roomkey);
                    
                }
            }
        }
         for(auto x: visited)
         {
             if(!x)
             {
                 return false;
             }
         }
        return true;
    }
};