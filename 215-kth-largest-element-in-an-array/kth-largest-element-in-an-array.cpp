class Solution {
private:
    int partition(vector<int>& nums, int s, int e) {
        int pivot = nums[e]; 
        int pivotIndex = s;  

        for (int i = s; i < e; i++) {
            if (nums[i] > pivot) { 
                swap(nums[i], nums[pivotIndex]);
                pivotIndex++;
            }
        }

        swap(nums[pivotIndex], nums[e]); 
        return pivotIndex;
    }

    int quickSelect(vector<int>& nums, int s, int e, int k) {
        if (s <= e) {
            int p = partition(nums, s, e);

            if (p == k) {
                return nums[p]; 
            } else if (p > k) {
                return quickSelect(nums, s, p - 1, k); 
            } else {
                return quickSelect(nums, p + 1, e, k); 
            }
        }
        return -1; 
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        int s = 0;
        int e = nums.size() - 1;

       return quickSelect(nums, s, e, k-1);
       
    }
};