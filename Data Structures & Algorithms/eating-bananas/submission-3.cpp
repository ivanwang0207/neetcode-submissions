class Solution {

private:
    int binarySearch(const vector<int>& piles, int lb, int hb, const int maxTime) {
        int mid = lb + (hb - lb) / 2;

        if (lb == hb) return mid;

        // estimate the required time
        int time = 0;
        for(auto& p : piles) {
            time += std::ceil((double)p / mid);
        }
        if (time > maxTime) {
            return binarySearch(piles, mid + 1, hb, maxTime);
        } else {
            return binarySearch(piles, lb, mid, maxTime);
        }
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // find the max value in piles
        int maxVal = piles[0];
        for(auto& p : piles){
            if (p > maxVal) maxVal = p;
        }

        // use Binary Search for range [1, maxVal]
        return binarySearch(piles, 1, maxVal, h);
    }
};
