class MyCalendar {
public:
    set<pair<int,int>> events;
    MyCalendar() {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    }
    
    bool book(int start, int end) {
        for(auto &it : events){
            if(start < it.second && end > it.first) return false;
        }
        events.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */