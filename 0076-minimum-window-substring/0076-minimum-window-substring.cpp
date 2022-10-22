class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> map;
        for (auto& c : t) map[c]++;
        
        // two pointer method
        // shift right pointer until all characters in t are found
        // then shift left pointer to create the smallest substr
        
        string res = "";
        
        int count = 0;
        
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            if (map[s[r]] > 0) count++;
            map[s[r]]--;
            // found the string with all chars
            // shift left pointer each time and check if its a valid substr
            if (count == t.length()) {
                while (l <= r && count == t.length()) {
                    // this is a valid string so store it as our result
                    if (res == "" || r - l + 1 < res.length()) {
                        res = s.substr(l, r - l + 1);
                    }
                    
                    // shift the left pointer to the right by one
                    if (map.find(s[l]) != map.end()) {
                        map[s[l]]++;
                        
                        // if incrementing map[s[l]] results in a value greater than 0,
                        // then we have to decrement count because there is no s[l] char in our substr
                        if (map[s[l]] > 0) count--;
                    }
                    l++;
                }
            }
        }
        
        return res;
    }
 
    
};