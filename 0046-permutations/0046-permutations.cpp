class Solution {
public:
    void findpermute(vector<int> &arr, vector<int> &diary, vector<vector<int>> &res, vector<bool> &visited) {
        if(diary.size() == arr.size()) {
            res.push_back(diary);
            return;
        }
        for (int i = 0; i<arr.size(); i++) {
            if(visited[i]) {
                continue;
            } 
            visited[i] = true;
            diary.push_back(arr[i]);
            findpermute(arr, diary, res, visited);
            visited[i] = false;
            diary.pop_back();
            
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>diary;
        vector<vector<int>>res;
        vector<bool> visited (nums.size(), false);
        findpermute(nums, diary, res, visited);
        return res;
    }
};