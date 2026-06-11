class Solution {

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        
        while(left < right) {
            int mid = left + (right - left) / 2;

            // x > (arr[mid] + arr[mid + k]) / 2 -> try to move window to the right
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else { // try to move window to the left
                right = mid;
            }
        }

        return vector<int>(
            arr.begin() + left, 
            arr.begin() + left + k);
    }
};