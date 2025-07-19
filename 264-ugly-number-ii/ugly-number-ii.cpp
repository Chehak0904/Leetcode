class Solution {
public:
    
    void fun(long long n,set<int>&st){
        if(n>INT_MAX || st.count(n)) return;
        st.insert(n);
        fun(n*2,st);
        fun(n*3,st);
        fun(n*5,st);
    }
    int nthUglyNumber(int n) {
        set<int>st;
        fun(1,st);
        for(auto it:st){
            if(--n==0){
                return it;
            }
        }
        return 0;
        
    }
};