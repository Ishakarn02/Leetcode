class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1, Maxlen = 1;

        if(nums.size() == 1){
            return 1;
        }

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                inc++;
                dec = 1;
            }
            else if(nums[i] < nums[i-1]){
                dec++;
                inc = 1;
            }
            else{
                inc = dec = 1;
            }
            Maxlen = max({Maxlen, inc, dec});
        }
        return Maxlen;
    }
};