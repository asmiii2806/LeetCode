class Solution {
public:
    string breakPalindrome(string palindrome) {
       if(palindrome.size()==1){
            return "";
        }
        for(int i=0;i<palindrome.size()/2;i++){//searching till half of the string if string is odd half -1
            if(palindrome[i]!='a'){
                palindrome[i]='a';//to make a lexilogically smaller non palendromic string
                return palindrome;
            }
        }
        palindrome[palindrome.size()-1]='b';
        return palindrome;
     
    }
};