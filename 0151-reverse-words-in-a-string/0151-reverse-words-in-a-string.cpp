class Solution {
public:
    string reverseWords(string str)
    {
                  /* int i;
        for(i = 0; i < s.length(); i++){
        if(s[i]==' '){
        continue;
        }
        else if(s[i]!=' '){
        break;
        }
        }

        int j = s.length()-1;
        for(j; j >= 0; j--){
        if(s[j]==' '){
        continue;
        }
        else if(s[j]!=' '){
        break;
        }
        }
        s = s.substr(i, j-i+1);

        //modifying my string to remove multiple spaces in b/w
        for(int i = 0; i < s.length();i++){
            if(s[i]==' ' && s[i+1]==' '){
                s.erase(i, 1);
                i=i-1;
        }
        }
        
        //reversing the string
        int f = 0, l = s.length()-1;
        while(f<=l){
            swap(s[f], s[l]);
            f++;
            l--;
        }
        int start = 0;
        int flag = 0;
        for(int i = 0; i <= s.length(); i++){
            if(s[flag]==' ' || s[flag]=='\0'){
                int end = flag-1;
                while(start<=end){
                    swap(s[start], s[end]);
                    start++;
                    end--;
                }
                start = flag+1;
            }
            flag++;
        }
        
        return s;
        }*/
        
         string word, ans="";
        stringstream ss(str);
        
        while(ss>>word){
            ans = word + " " + ans;
        }
        ans.pop_back();
        return ans;
    }

};