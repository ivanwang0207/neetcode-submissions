class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        vector<int> ans(2);

        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                ans = vector<int>({i + 1, j + 1});
                break;
            } else if (sum < target){
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};