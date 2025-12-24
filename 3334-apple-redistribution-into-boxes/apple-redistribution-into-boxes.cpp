class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=apple[i];
        }
        sort(capacity.begin(),capacity.end());
        int res=0;
        for(int i=m-1;i>=0;i--){
            total-=capacity[i];
            res++;
            if(total<=0){
                break;
            }
        }
        return res;

    }
};