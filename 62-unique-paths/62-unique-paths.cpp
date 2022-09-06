class Solution {
public:
    unordered_map<string, int>mp;
    int totalways(int currentrow, int currentcol, int m, int n)
    {
        if(currentrow==m-1 || currentcol==n-1)
        {
            return 1;
            
        }
        
        if(currentrow>=m || currentcol>=n)
        {
            return 0;
        }
        string currentkey=to_string(currentrow)+"_"+to_string(currentcol);
        
        if(mp.find(currentkey)!=mp.end())
            return mp[currentkey];
        
        int rightmove=totalways(currentrow, currentcol+1, m, n);
        int downmove=totalways(currentrow+1, currentcol, m,n);
        
        mp[currentkey]=rightmove+downmove;
        
       return  rightmove+downmove;
    }
    int uniquePaths(int m, int n) {
            return totalways(0,0,m,n);
        
    }
};