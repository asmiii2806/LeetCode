class Solution {
public:
    
      map<int,int> mp;
    int res=0;

    void fun(vector<string> &arr,int l,int r){

        int count=0;

        // Base codition:- If frequency of any of the alphabet is greater than 1, at that time we need to backtrack (return) otherwise increment the counter.

        for(int i=0;i<26;i++){
            if(mp[i]==1){
                count++;
            }
            if(mp[i]>1){
                return;
            }
        }

        // updating the maximum length
        res=max(res,count);

        // Main Approach
        for(int i=l;i<r;i++){
            for(auto j: arr[i]){
                mp[j-'a']++;
            }

            fun(arr,i+1,arr.size());

            for(auto j: arr[i]){
                mp[j-'a']--;
            }

            
        }
       
    }
    int maxLength(vector<string>& arr) {
         fun(arr,0,arr.size());

        // Returning the final maximum possible length
        return res;
    }
};