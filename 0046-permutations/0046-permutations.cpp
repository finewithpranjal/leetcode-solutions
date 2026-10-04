class Solution {
public:
    void getpermutations(int idx, vector<int>& arr, vector<vector<int>>& ans) {
        // Base Case
        if (idx == arr.size()) {
            ans.push_back(arr);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            swap(arr[idx], arr[i]); //idx place => ith element swap
            getpermutations(idx + 1, arr, ans);
            swap(arr[idx], arr[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getpermutations(0, nums, ans);
        return ans;
    }
};