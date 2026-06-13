class Solution {

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::copy(nums2.begin(), nums2.end(), nums1.begin() + m);
        
        std::vector<int> tmp;
        int l = 0, r = m + n - 1;
        tmp.reserve(r - l + 1);
        
        int p1 = 0;
        int p2 = m;

        while(p1 <= m - 1 && p2 <= r) {
            if (nums1[p1] < nums1[p2]){
                tmp.push_back(nums1[p1++]);
            } else {
                tmp.push_back(nums1[p2++]);
            }
        }

        while(p1 <= m - 1){
            tmp.push_back(nums1[p1++]);
        }
        while(p2 <= r){
            tmp.push_back(nums1[p2++]);
        }

        for(int i = 0; i < tmp.size(); ++i){
            nums1[i] = tmp[i];
        }
    }
};