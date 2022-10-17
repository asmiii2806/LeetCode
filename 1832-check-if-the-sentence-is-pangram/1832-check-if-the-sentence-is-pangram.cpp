class Solution {
public:
    bool checkIfPangram(string sentence) {
       vector<int> arr(26,0); // array to store frequency of characters
        
        for(int i=0;i<sentence.length();i++) {
            arr[sentence[i] - 'a']++;
        }
        
        for(int i=0;i<26;i++) {
            if(arr[i] == 0) return false;
        }
        
        return true;
       
    }
};