class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        unordered_map<int,int> even, odd;

        int cnte = 0, cnto = 0;

        int max1_e = 0, max2_e = 0;
        int max1_o = 0, max2_o = 0;

        for(int i=0;i<nums.size();i++){

            if(i%2==0){

                cnte++;
                even[nums[i]]++;

                if(even[nums[i]] > even[max1_e]){
                    max2_e = max1_e;
                    max1_e = nums[i];
                }
                else if(nums[i] != max1_e && even[nums[i]] > even[max2_e]){
                    max2_e = nums[i];
                }

            }
            else{

                cnto++;
                odd[nums[i]]++;

                if(odd[nums[i]] > odd[max1_o]){
                    max2_o = max1_o;
                    max1_o = nums[i];
                }
                else if(nums[i] != max1_o && odd[nums[i]] > odd[max2_o]){
                    max2_o = nums[i];
                }
            }
        }

        if(max1_e == max1_o){

            return min(
                cnte - even[max1_e] + cnto - odd[max2_o],
                cnte - even[max2_e] + cnto - odd[max1_o]
            );
        }

        return cnte - even[max1_e] + cnto - odd[max1_o];
    }
};