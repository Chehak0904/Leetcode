class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        set<int> players;

       
        for (auto& match : matches) {
            int winner = match[0], loser = match[1];
            losses[loser]++;
            players.insert(winner);
            players.insert(loser);
        }

        vector<int> noLoss, oneLoss;

    
        for (int player : players) {
            int lossCount = losses[player];  
            if (lossCount == 0) noLoss.push_back(player);
            else if (lossCount == 1) oneLoss.push_back(player);
        }

        return {noLoss, oneLoss};
    }
};
