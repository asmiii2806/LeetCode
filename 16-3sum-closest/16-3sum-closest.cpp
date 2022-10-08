class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());     // sort the given nums array in ascending order to use the two pointers technique. 
        int minDiff = INT_MAX, closestVal;
        
        for(int i = 0; i<n-2; i++){
            int left = i+1, right = n-1;               // left and right is the range of two pointers
            
            while(left < right){
                int sum3 = nums[i] + nums[left] + nums[right];
                int tempDiff = abs(sum3 - target);

                if(tempDiff == 0)   return sum3;           // as this is the best possible answer, (no need to run program more if the best possible answer is found).
                if(tempDiff < minDiff)  minDiff = tempDiff, closestVal = sum3;
                
                sum3 < target ? ++left : --right;
            }
        }
        return closestVal;
     
    }
};