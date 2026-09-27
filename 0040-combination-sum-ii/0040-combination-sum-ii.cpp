class Solution {
public:
    void findCombinations(int idx, vector<int>& arr, vector<int>& ds,
                          vector<vector<int>>& ans, int target) {
        // Base Case
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            if (i > idx && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;

            // Picking element
            ds.push_back(arr[i]);
            findCombinations(i + 1, arr, ds, ans, target - arr[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        findCombinations(0, candidates, ds, ans, target);
        return ans;
    }
};