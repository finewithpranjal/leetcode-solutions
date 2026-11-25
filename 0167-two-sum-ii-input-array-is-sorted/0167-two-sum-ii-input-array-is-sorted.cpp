class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size()-1;
        vector<int>ans(2);
        while(low < high) 
        {    

            int sum = numbers[low] + numbers[high];
             if(sum == target) {
                 ans[0] = low+1;
                 ans[1] = high+1;
                 break;
             }

             if(sum < target) 
             {
               low++;
             }
             if(sum > target)
             {
                high--;
             }

         }
         return ans;
    }
};