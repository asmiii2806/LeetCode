class Solution {
public:
    unordered_map<int,int>mp;
    
    int minways(int n, int target)
    {
        if(target==n)
            return 1;
        if(target>n)
            return 0;
        
        int currentkey=target;
        
        if(mp.find(currentkey)!=mp.end())
            return mp[currentkey];
        
        int onejump=minways(n, target+1);
        int twojump=minways(n, target+2);
        
         mp[currentkey]=onejump+twojump;
                return onejump+twojump;

    }
    int climbStairs(int n)
    {
      return minways(n,0);
        
        
    }
};