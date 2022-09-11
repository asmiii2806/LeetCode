class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            sort(matrix.begin(), matrix.end());
    // int i=matrix.size();
    // int j=matrix[0].size();

    int low=0;
    int high=matrix[0].size()-1;
    int mid=low+(high-low)/2;

    while(low<matrix.size() && high>=0)
    {
        if(matrix[low][high]==target)
        {
            return true;

        }

        if(matrix[low][high]>target)
        {
            high--;

        }
        else
        {
           low++;
        }

    }
    return false;


    }
};