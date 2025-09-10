class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        vector<char> ch = {'A','C','G','T'};
        unordered_set<string> valid(bank.begin(), bank.end());  // valid genes
        unordered_set<string> visited;
        visited.insert(startGene);
        
        queue<pair<string,int>> q;
        q.push({startGene, 0});
        
        while(!q.empty()){
            string s = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            if(s == endGene) return dis;
            
            for(int i = 0; i < s.length(); i++){
                for(char c : ch){
                    if(s[i] != c){
                        string temp = s;
                        temp[i] = c;
                        if(valid.count(temp) && !visited.count(temp)){
                            q.push({temp, dis+1});
                            visited.insert(temp);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
