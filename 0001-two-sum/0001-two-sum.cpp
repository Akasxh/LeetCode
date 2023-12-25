#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i) {
            int num1 = nums[i];
            for(int j = i + 1; j < nums.size(); ++j) {
                int num2 = nums[j];
                if (num1 + num2 == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
