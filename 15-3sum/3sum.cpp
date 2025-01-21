class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        if(n < 3)
        return {};

        if(nums[0] > 0)
        return {};

        for(int i=0; i<n; i++){
            if(nums[i] > 0)
            break;

            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = n-1;
            int sum = 0;

            while(left < right){
                sum =nums[i] + nums[left] + nums[right];

                if(sum > 0)
                right--;

                else if(sum < 0)
                left++;

                else{
                    ans.push_back({nums[i], nums[left], nums[right]});

                    int last_left_occur = nums[left];
                    int last_right_occur = nums[right];

                    while(left < right && nums[left] == last_left_occur){
                        left++;
                    }
                    while(left < right && nums[right] == last_right_occur){
                        right--;
                    }
                }
            }

        }
        return ans;
    }
};