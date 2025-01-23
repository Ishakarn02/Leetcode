class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_smallest = INT_MAX;
        int second_smallest = INT_MAX;

        for(int num : nums){
            if(num <= first_smallest){
                first_smallest = num;
            }
            else if(num <= second_smallest){
                second_smallest = num;
            }
            else{
                return true;
            }
        }
        return false;
    }
};