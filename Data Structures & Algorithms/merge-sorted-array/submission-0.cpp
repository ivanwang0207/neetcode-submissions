class Solution {

private:

    void mergeProc(vector<int>& nums, int l, int mid, int r) {
        std::vector<int> tmp;
        tmp.reserve(r - l + 1);
        
        int p1 = l;
        int p2 = mid + 1;

        while(p1 <= mid && p2 <= r) {
            if (nums[p1] < nums[p2]){
                tmp.push_back(nums[p1++]);
            } else {
                tmp.push_back(nums[p2++]);
            }
        }

        while(p1 <= mid){
            tmp.push_back(nums[p1++]);
        }
        while(p2 <= r){
            tmp.push_back(nums[p2++]);
        }

        for(int i = 0; i < tmp.size(); ++i){
            nums[l + i] = tmp[i];
        }
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        mergeProc(nums, l, mid, r);
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // concat nums2 to nums1 
        std::copy(nums2.begin(), nums2.end(), nums1.begin() + m);
        mergeSort(nums1, 0, m + n - 1);
    }
};