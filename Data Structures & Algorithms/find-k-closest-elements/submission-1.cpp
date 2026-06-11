class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        std::sort(arr.begin(), arr.end(),
                  [=](const int& a, const int& b) {
                    int da = abs(a - x);
                    int db = abs(b - x);
                    if (da == db)
                        return a < b;
                    return da < db;
                  });

        arr.erase(arr.begin() + k, arr.end());
        std::sort(arr.begin(), arr.end());
        return arr;
    }
};