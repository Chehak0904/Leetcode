
class Solution {
public:
    bool isSafe(int n,vector<string>&board,int r,int c){
        for(int row=r-1;row>=0;row--){
            if(board[row][c]=='Q'){
                return false;
            }
        }
        for(int i=r-1,j=c-1;i>=0 && j>=0 ;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
          for(int i=r-1,j=c+1;i>=0 && j<n ;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
        

    }
    void solve(int n,vector<vector<string>>&output,vector<string>temp,int r){
        if(r==n){
            output.push_back(temp);
        }
        
        for(int c=0;c<n;c++){
            if(isSafe(n,temp,r,c)){
                temp[r][c]='Q';
                solve(n,output,temp,r+1);
                temp[r][c]='.';
                
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));
        solve(n, ans, temp, 0);
        return ans;
    }
};