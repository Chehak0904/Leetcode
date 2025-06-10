class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid=j+(i-j)/2;
            if(arr[mid]<=arr[n-1]){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return arr[ans];
        
    }
};