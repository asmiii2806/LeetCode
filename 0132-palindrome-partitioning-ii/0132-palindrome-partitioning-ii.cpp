class Solution {
public:
    int minimumcuts(string &s, int start, int end,vector<int>&v)
    {
        if(isPalindrome(s,start,end))
        {
            return 0;
        }
        if(v[start]!=-1)
        {
            return v[start];
        }
        int finalans=INT_MAX;
        for(int i=start; i<end; i++)
        {
            if(isPalindrome(s,start,i))
            {
                int ans=1+minimumcuts(s, i+1,end,v);
                finalans=min(ans,finalans);
                v[start]=finalans;
                
                
            }
        }
        return v[start];
        
    }
    bool isPalindrome(string &s, int start,int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
            {
                return false;
                
            }
        
            start++;
            end--;
            
        }
        return true;
        
    }
    int minCut(string s) {
        vector<int>v(2001,-1);
        
      return minimumcuts(s,0,s.length()-1,v);  
    }
    
    
};