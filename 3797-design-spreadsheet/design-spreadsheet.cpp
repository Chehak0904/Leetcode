class Spreadsheet {
public:
    vector<vector<int>> vec;
    Spreadsheet(int rows) {
        vec.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';  
        string r=cell.substr(1);
        int row=stoi(r)-1;
        vec[row][col]=value; 
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        string row=cell.substr(1);
        int r=stoi(row)-1;
        vec[r][col]=0; 
             
    }
    int solve(string s){
        if(isdigit(s[0])){
            return stoi(s);
        }
        int col=s[0]-'A';
        int row=stoi(s.substr(1))-1;
        return vec[row][col];
    }
    
    int getValue(string formula) {
        string exp=formula.substr(1);
        int pos=exp.find('+');
        int left=solve(exp.substr(0,pos));
        int right=solve(exp.substr(pos+1));
        return left+right;
         
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */