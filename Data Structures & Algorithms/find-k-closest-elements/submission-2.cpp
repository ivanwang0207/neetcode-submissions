class Solution {

private:
    int binarySearch(vector<int>& arr, int left, int right, int x, int k) {
        int mid = left + (right - left) / 2;
        if (left == right)
            return mid;

        if (x - arr[mid] > arr[mid + k] - x) {
            return binarySearch(arr, mid + 1, right, x, k);
        } else {
            return binarySearch(arr, left, mid, x, k);
        }
    }

public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        int start = binarySearch(arr, left, right, x, k);

        return vector<int>(
            arr.begin() + start, 
            arr.begin() + start + k);
    }
};