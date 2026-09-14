class Solution {
public:
    bool checkpalindrome(string element) {
        int n = element.size();
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (element[i] != element[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }
    void fun(string s, int n, int idx, vector<string>& diary,
             vector<vector<string>>& res) {
        // Base Case
        if (idx == n) {
            res.push_back(diary);
        }

        for (int end = idx; end < n; end++) {
            string element = s.substr(idx, end - idx + 1);
            if (checkpalindrome(element)) {
                diary.push_back(element);
                fun(s, n, end + 1, diary, res);
                diary.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        int idx = 0;
        vector<string> diary;
        vector<vector<string>> res;
        fun(s, n, idx, diary, res);

        return res;
    }
};