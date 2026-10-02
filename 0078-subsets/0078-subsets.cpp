class Solution {
public:
    void subsets(int idx, int n, vector<int>& arr, vector<vector<int>>&ds,vector<int>& diary) {

        if (idx == n) {
            ds.push_back(diary);
            return;
        }
        // Picking an element
        diary.push_back(arr[idx]);
        subsets(idx + 1, n, arr, ds, diary);

        diary.pop_back();
        // Not picking an element
        subsets(idx + 1, n, arr, ds, diary);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ds;
        vector<int>diary;
        subsets(0, n, nums, ds, diary);
        return ds;
    }
};