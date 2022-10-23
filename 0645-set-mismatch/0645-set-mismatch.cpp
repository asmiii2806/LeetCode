class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
         int n=nums.size();
        vector<int> freq(n+1, 0);
        
        for(auto i:nums)
            freq[i]++;
        
        int repeat=0, duplicate=0;
        
        for(int i=1;i<=n;i++){
            if(freq[i]==0)
                duplicate=i;
            
            else if(freq[i]==2)
                repeat=i;
        }
        
        return {repeat,duplicate};
      
    }
};