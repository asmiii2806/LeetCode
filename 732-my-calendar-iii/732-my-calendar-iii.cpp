class MyCalendarThree {
public:
     struct node {
        int type, loc; // type 1: start, type -1 : end
    };
    
    vector<node> list;
    MyCalendarThree() {
            
    }
    
    int book(int start, int end) {
      list.push_back({1, start});
        list.push_back({-1, end});
        sort(list.begin(), list.end(), [](const node &a, const node &b){
            if(a.loc == b.loc) return a.type < b.type;
            return a.loc < b.loc; 
        });
        int cnt = 0;
        int ans = 0;
        for (node &cur : list) {            
            cnt += cur.type;
            if(ans < cnt) ans = cnt;
        }        
        return ans;
    }
    
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */