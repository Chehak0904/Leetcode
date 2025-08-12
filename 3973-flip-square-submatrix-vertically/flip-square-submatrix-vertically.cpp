class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=0;i<k;i++){
            int sx=x;
            int sy=y+i;
            int ex=x+k-1;
            while(sx<ex){
                swap(grid[sx][sy],grid[ex][sy]);
                sx++;
                ex--;
            }

        }
        return grid;
    }
};