class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end());
        int ans = 0;
        
        int temp = INT_MIN;
        int maxx = INT_MIN;
        
        for(int i=properties.size()-1;i>=0;i--){
        if(i != properties.size() - 1 && properties[i][0] != properties[i+1][0]) maxx = max(maxx, temp);
            if(properties[i][1] < maxx) ans++;
            temp = max(temp, properties[i][1]);
        }
        
        return ans;
    
    }
};