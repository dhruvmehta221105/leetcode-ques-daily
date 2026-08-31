class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;

        // put all non zero number in front starting from index 0
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }
        }

        // filling the rest array size left numbers with 0
        while (j < nums.size()) {
            nums[j] = 0;
            j++;
        }
    }
};