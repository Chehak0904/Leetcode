class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total=0;
        for(int i:apple){
            total+=i;
        }
        sort(capacity.begin(),capacity.end());
        int i=capacity.size()-1;
        int cnt=0;
        while(i>=0 && total>0){
            total-=capacity[i];
            cnt++;
            i--;
        }
        return cnt;

    }
};