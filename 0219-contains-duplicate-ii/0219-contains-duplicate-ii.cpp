class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         int n = nums.size();
    unordered_map<int,vector<int>>mp;
    
    for(int i=0;i<n;i++){
        mp[nums[i]].push_back(i);
    }
    
    for(auto it:mp){
        int e = it.second.size();
        auto vec = it.second;
        
        if((e) > 1){
            for (int i=0;i<e;i++){
                for(int j=i+1;j<e;j++){
                    if(abs(vec[i]-vec[j])<=k)return true;
                }
            }
        }
    }
    return false;
 
    }
};