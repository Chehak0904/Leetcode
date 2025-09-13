class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxFreqSum(string s) {
        int maxV=0, maxC=0;
        vector<int> arr(26,0);
        for(char c:s){
            arr[c-'a']++;
            if(isVowel(c)) maxV=max(maxV,arr[c-'a']);
            else maxC=max(maxC,arr[c-'a']);
        }
        return maxV+maxC;
    }
};