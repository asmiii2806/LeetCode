class TimeMap {
public:
    
     unordered_map<int , string> p1; //used to store value at various timestamps
    unordered_map<string , vector<int>> p2;  
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
           if(p2.find(key) == p2.end()) //if key not present make a temp array and store timestamps for that new key
        {
            vector<int> temp;
            temp.push_back(timestamp);
            
            p2[key] = temp;
        }
        else
            p2[key].push_back(timestamp);
        
        p1[timestamp] = value; 
    }
    
    string get(string key, int timestamp) {
         if(p2.find(key) == p2.end())
            return "";
        
        
        //out of bound cases
        string ans = "";
        if(timestamp < p2[key][0])
            ans = "";
        
        else if(timestamp > p2[key][p2[key].size()-1])
            ans = p1[p2[key][p2[key].size()-1]];
         
        //if present case
        else if(p1.find(timestamp) != p1.end())
            ans = p1[timestamp];
        
        //if in range but not exactly present
        else
        {
            int s = 0;
            int e = p2[key].size() - 1;
            
            while(s < e)
            {
                int mid = (s + e)/2;
                
                if(p2[key][mid] < timestamp)
                    e = mid - 1;
                
                else
                    s = mid + 1; 
            }
            
            ans = p1[p2[key][s]];
        }
        
        return ans;
    }
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */