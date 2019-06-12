class Solution {
public:
    int checkArray(vector<int>& nums) {
        for (int i =  0; i < nums.size(); ++i) {
            if (nums[i] != i + 1)  {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }

    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0;  i < nums.size(); i++) {
            // Do nothing if in position
            // Do nothing if out of bounds
            // Do nothing if target position already contains correct value
            while (
                nums[i] != i + 1  &&
                nums[i] - 1 >= 0 && nums[i] - 1 < nums.size() &&
                nums[nums[i] - 1] != nums[i]
            ) {
                // Swap to i = value
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        return checkArray(nums);
    }
};