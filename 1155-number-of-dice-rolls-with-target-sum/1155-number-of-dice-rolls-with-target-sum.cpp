class Solution {
public:
            #define MOD 1000000007

    unordered_map<string, int >mp;
    
    int totalways(int n, int k, int targetsum)
    {
        
        if(n==0 && targetsum==0)
            return 1;
        
        if(n==0 || targetsum<=0)
            return 0;
        int ways=0;
        
        string currentkey=to_string(n)+"_"+to_string(targetsum);
        
       if(mp.find(currentkey)!=mp.end())
       {
           return mp[currentkey];
           
       }
       for(int i=1; i<=k; i++)
       {
           if(i<=targetsum)
           {
           int ans=totalways(n-1, k,targetsum-i);
                       ways=(ways%MOD+ans%MOD)%MOD;

           }
       }
        
        mp[currentkey]=ways%MOD;
        
       return ways; 
    }
    
    int numRollsToTarget(int n, int k, int target)
    {
       return totalways(n,k,target); 
        
    }
};