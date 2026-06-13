class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // the count of majority - the count of remaining > 0
        int majorityElement = -1;
        int counter = 0;

        for(auto& i : nums) {
            if (counter == 0) {
                majorityElement = i;
                counter++;
            } else {
                if (majorityElement == i) {
                    counter++;
                } else {
                    counter--;
                }
            }
        }
        return majorityElement;
    }
};