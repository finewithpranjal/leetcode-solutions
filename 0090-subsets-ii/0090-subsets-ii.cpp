class Solution {
public:
    void subsets(int idx, vector<int> &arr, vector<int> &diary, vector<vector<int>> &res ) {
        res.push_back(diary);
        for (int i = idx; i<arr.size(); i++) {
            if(i != idx && arr[i] == arr[i-1]) continue;
            diary.push_back(arr[i]);
            subsets(i+1, arr, diary, res);
            diary.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>diary;
        vector<vector<int>>res;
        subsets(0, nums, diary, res);
        return res;

    }
};