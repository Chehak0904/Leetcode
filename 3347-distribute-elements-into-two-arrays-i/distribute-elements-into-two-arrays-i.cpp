class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0;
        int j=n-1;
        ans[0]=nums[0];
        ans[n-1]=nums[1];
        for(int k=2;k<n;k++){
            if(ans[i]>ans[j]){
                i++;
                ans[i]=nums[k];
            }
            else{
                j--;
                ans[j]=nums[k];
            }
        }
        int l=j;
        int r=n-1;
        while(l<r){
            swap(ans[l],ans[r]);
            l++;
            r--;
        }
        return ans;
        
    }
};