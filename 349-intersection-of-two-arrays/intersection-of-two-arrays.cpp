class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ans;
        unordered_set<int> set1(nums1.begin(), nums1.end());

        for(int num : nums2){
            if(set1.find(num) != set1.end()){
                ans.insert(num);
            }
        }
        vector<int> result(ans.begin(), ans.end());
        
        return result;
    }
};