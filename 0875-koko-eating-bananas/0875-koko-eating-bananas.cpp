class Solution {
public:
    long long returnhours(vector<int> arr, int n, int speed) {
        long long h = 0;
        for (int i = 0; i < n; i++) {
            h = h + arr[i] / speed;
            if (arr[i] % speed != 0) {
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = -1;

        while (low <= high) {
            int guess = low + (high - low) / 2;
            long long hours = returnhours(piles, n, guess);
            if (hours > h) { // No case
                low = guess + 1;
            } else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
    };