class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int minValue = nums[0];
        int answer = -1;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] > minValue) {
                answer = max(answer, nums[i] - minValue);
            }

            minValue = min(minValue, nums[i]);
        }

        return answer;
    }
};