class MyCalendarTwo {
public:
    map<int,int>mp;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        bool tripleBook=false;
        int sum=0;
        for(auto it:mp){
            sum+=it.second;
            if(sum>=3){
                tripleBook=true;
            }
        }
        if(tripleBook==true){
            mp[startTime]-=1;
            mp[endTime]+=1;
            return false;
        }
        return true;

        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */