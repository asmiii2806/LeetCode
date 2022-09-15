class Solution {
public:
        #define MOD 1000000007

    int totalways(int n, int k, int target, vector<vector<int>>&v)
    {
        if(target==0 && n==0)
        {
            return 1;
        }
        if(n==0 && target!=0)
        {
            return 0;}
        
        if(v[n][target]!=-1)
            return v[n][target];
        
        int ways=0;
        
        // (A+B)%C=(a%b+b%c)%c
        for(int i=1; i<=k; i++)
        {
            if(i<=target)
            {
           int tempAns= totalways(n-1,k, target-i,v);
            ways=(ways%MOD+tempAns%MOD)%MOD;
            }
           //ways=ways % MOD;
           //ways=(ways+tempAns)% MOD; 
          //   v[n][target]=ways%MOD;
        
        }
                     v[n][target]=ways%MOD;

        return ways;
        
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>>v(32, vector<int>(10001, -1));
        
      return totalways(n,k,target,v);
        
    }
};