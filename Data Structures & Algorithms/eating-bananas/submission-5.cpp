class Solution {

private:
    int binarySearch(const vector<int>& piles, int left, int right, int maxTime) {
        
        auto calcTime = [&](const int& rate) -> int {
            int sum = 0; 
            for(auto& p : piles) {
                sum += std::ceil((double)p / rate);  
            }
            return sum;
        };

        int mid = left + (right - left) / 2;
        if (left == right) return mid;

        int currTime = calcTime(mid);
        if (currTime > maxTime) {
            return binarySearch(piles, mid + 1, right, maxTime);
        } else {
            return binarySearch(piles, left, mid, maxTime); 
        }
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // get the min and max eating rate is the greatest number in piles 
        int left = 1;
        int right = *(std::max_element(piles.begin(), piles.end()));

        // Binary Search
        return binarySearch(piles, left, right, h);
    }
};
