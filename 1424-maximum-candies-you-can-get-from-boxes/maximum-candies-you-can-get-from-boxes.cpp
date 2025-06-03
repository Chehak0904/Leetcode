class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        int MAX = 0 ;
        int n = status.size() ;
        vector<bool> visited(n,false) , hasBox(n,false) ;
        queue<int> q ;

        for ( int i : initialBoxes ){
            hasBox[i] = true ;
            if ( status[i] == 1 && !visited[i] ) q.push(i) ;
        }

        while ( !q.empty() ){

            auto index = q.front() ;
            q.pop() ;
            if ( visited[index] ) continue ;
            visited[index] = true ;
            MAX += candies[index] ;

            for ( auto key : keys[index] ){
                if ( status[key] == 0 ){
                    status[key]= 1 ;
                    if ( hasBox[key] && !visited[key] ){
                        q.push(key) ;
                    }               
                }
            }
            for ( auto it : containedBoxes[index] ){
                hasBox[it] = true ;
                if ( !visited[it] && status[it] == 1 ){
                    q.push(it) ;
                }
            }
        }
        
        return MAX ;

    }
};