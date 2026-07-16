class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // for Kth largest use min heap
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;

        for (int i = 0; i<k; i++) {
           pq.push(nums[i]);
        }
        for (int j = k; j<n; j++) {
            if(nums[j] > pq.top()) {
                pq.pop();
                pq.push(nums[j]);
            }
        }
       return pq.top();
        
    }
};