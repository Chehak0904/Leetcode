class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x=source[0]+source[1];
        int y=target[0]+target[1];
        int a=(source[0]-source[1]);
        int b=(target[0]-target[1]);
        if((x==y)||(a==b)){return 1;}
        if((x%2==0 && y%2!=0)||(x%2!=0 && y%2==0)) return -1;
        else return 2;

        
    }
};