class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxi=-1;
        int i=0;
        int j=n-1;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int area=w*h;
            maxi=max(maxi,area);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return maxi;
    }
};