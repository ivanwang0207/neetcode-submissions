class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; // min. possible speed 
        int r = *max_element(piles.begin(), piles.end()); // max. valid speed
        int result = r;

        // from l to r is ordered, we can use binary search to find 
        // the min. valid speed

        while(l < r) {

            int mid = l + (r - l) / 2;

            int time = 0;
            for(int i = 0; i < piles.size(); i++){
                time += std::ceil(static_cast<double>(piles[i]) / mid);
            }
            if (time <= h) {
                r = mid;
                result = mid;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};
