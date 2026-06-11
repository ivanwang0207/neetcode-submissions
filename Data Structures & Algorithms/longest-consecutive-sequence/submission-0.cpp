class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // // brute force solution: O(n^2)
        // // the worse case: [1, 2, 3, 4, 5, 6, 7]
        // int curMaxLength = 0;
        // for(int i = 0; i < nums.size(); i++){
        //     int num = nums[i];
        //     int curLength = 1;
        //     while(std::find(nums.begin(), nums.end(), num + 1) != nums.end()){
        //         curLength++;
        //         num++;
        //     }
        //     curMaxLength = std::max(curLength, curMaxLength);
        // }
        // return curMaxLength;

        // convert nums to a set
        std::unordered_set numsSet(nums.begin(), nums.end());

        int curMaxLength = 0;
        for(const auto& num : numsSet){
            if (numsSet.count(num - 1)){
                continue; // not a beginning number, since the previous num can be found
            }
            
            int nextNum = num + 1;
            int curLength = 1;
            while(numsSet.count(nextNum)){
                nextNum++;
                curLength++;
            }
            curMaxLength = std::max(curLength, curMaxLength);
        }
        return curMaxLength;
    }
};
