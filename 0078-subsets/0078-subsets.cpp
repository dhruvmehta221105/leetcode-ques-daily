class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;

        result.push_back({});

        for (int num : nums) {

            int size = result.size();

            for (int i = 0; i < size; i++) {

                vector<int> newSubset = result[i];

                newSubset.push_back(num);

                result.push_back(newSubset);
            }
        }

        return result;
    }
};