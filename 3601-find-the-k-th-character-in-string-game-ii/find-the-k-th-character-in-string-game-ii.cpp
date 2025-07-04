class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lens;
        long long l = 1;
        for (int i = 0; i < operations.size(); i++) {
            l *= 2;
            lens.push_back(l);
            if (l >= k)
                break;
        }
        int shifts=0;
        for(int i=lens.size()-1;i>=0;i--){
            long long half=lens[i]/2;
            if(k>half){
                k-=half;
                if(operations[i]==1){
                    shifts++;
                }
            }
        }

        return (shifts)%26+'a';
    }
};