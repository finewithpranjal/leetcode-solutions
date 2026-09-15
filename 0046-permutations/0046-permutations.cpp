class Solution {
public:
    void fun(vector<int>& arr, int n, vector<bool> &visited, vector<int>& diary,
             vector<vector<int>>& res) {
        // Base Case
        if (diary.size() == n) {
            res.push_back(diary);
            return;
        }
        
        // calling the function;
        for (int idx = 0;  idx<n;  idx++) {

            if(visited[idx]) {
                continue;
            }
           visited[idx] = true;
           diary.push_back(arr[idx]);
           
           fun(arr, n,  visited , diary, res);
           diary.pop_back();
           visited[idx] = false;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<int> diary;
        vector<vector<int>> res;
        vector<bool> visited(n, false);
        fun(nums, n, visited, diary, res);
        return res;
    }
};